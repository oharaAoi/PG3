#include <cstdio>
#include <string>
#include <chrono>

namespace chrono = std::chrono;

int main() {
	
	std::string original(100000, 'a');

	// ------------------------------------------------------------------ //
	// コピーを行う
	// ------------------------------------------------------------------ //
	std::chrono::system_clock::time_point copyStart, copyEnd;
	copyStart = std::chrono::system_clock::now();

	// コピー
	std::string copy = original;
	copyEnd = std::chrono::system_clock::now();

	// 時間を計算
	float copyElapsed = chrono::duration<float, std::micro>(copyEnd - copyStart).count();


	// ------------------------------------------------------------------ //
	// 移動を行う
	// ------------------------------------------------------------------ //
	std::chrono::system_clock::time_point moveStart, moveEnd;
	moveStart = std::chrono::system_clock::now();

	// 移動
	std::string move = std::move(original);
	moveEnd = std::chrono::system_clock::now();

	// 時間を計算
	float moveElapsed = chrono::duration<float, std::micro>(moveEnd - moveStart).count();

	// ------------------------------------------------------------------ //
	// 表示をする
	// ------------------------------------------------------------------ //

	printf("100,00文字を移動とコピーで比較しました\n");
	printf("コピー: %f\n", copyElapsed);
	printf("移動 : %f\n", moveElapsed);

	return 0;
}