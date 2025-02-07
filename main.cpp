#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <string>
#include <queue>
#include <thread>
#include <condition_variable>
#include <mutex>

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓ LoadCsv
//////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<std::vector<std::string>> ReadCSV(const std::string& filename) {
	std::vector<std::vector<std::string>> data;
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		return data;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::vector<std::string> row;
		std::stringstream ss(line);
		std::string cell;

		while (std::getline(ss, cell, ',')) {
			row.push_back(cell);
		}

		data.push_back(row);
	}

	file.close();
	return data;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓ main処理
//////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	std::mutex mutex;
	std::condition_variable condition;
	std::queue<std::vector<std::vector<std::string>>> q;
	bool exit = false;

	std::string filename = "map.csv";
	bool isDisplay = false;

	// -------------------------------------------------
	// ↓ 別スレッドでcsvを読み込むループ
	// -------------------------------------------------
	std::thread th([&]() {
		while (!exit) {
			{
				std::unique_lock<std::mutex> uniqueLock(mutex);
				condition.wait(uniqueLock, [&]() {return isDisplay || exit;});	// isDisplayがtrueになるまで待機

				if (exit) return;

				q.push(ReadCSV(filename));
				isDisplay = false;
				condition.notify_all();
			}
			condition.notify_all(); // メインスレッドを起こす
		}
				   });

	// -------------------------------------------------
	// ↓ mainループ
	// -------------------------------------------------
	std::vector<std::vector<std::string>> map;
	while (true) {
		int input = 0;
		printf("数字を入力して(1: ならcsvを読み込んで表示 0: 終了)\n");
		std::cin >> input;

		if (input == 0) {
			exit = true;
			break; // 終了
		}

		if (input == 1) {
			// 別スレッドで読み込みをするために競合が起きないようlockする
			{
				std::unique_lock<std::mutex> uniqueLock(mutex);
				isDisplay = true;
			}
			condition.notify_all();  // 待機しているスレッドを起動
		}
		
		// 別スレッドでのcsv読み込みが終了するまで待機を行う
		{
			std::unique_lock<std::mutex> uniqueLock(mutex);
			// qが空でなくなったら読み込み完了なためwaitを終了する
			condition.wait(uniqueLock, [&]() { return !q.empty(); });

			// CSVデータを取得
			map = q.front();
			q.pop();
		}

		if (!map.empty()) {
			for (const auto& row : map) {
				for (const auto& cell : row) {
					std::cout << cell << " ";
				}
				std::cout << std::endl;
			}
		}
	}

	{
		std::unique_lock<std::mutex> uniqueLock(mutex);
		exit = true;
		condition.notify_all();
	}

	th.join();

	return 0;
}