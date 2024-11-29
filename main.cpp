#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>

std::string extractKey(const std::string& email) {
    size_t gString = email.find('g');
    if (gString != std::string::npos && gString + 4 < email.size()) {
        return email.substr(gString + 1, 4); // gの次の4文字を取得
    }
    return ""; // 条件を満たさない場合は空文字
}


int main() {

    // ファイルパスを指定
    const std::string fileName = "PG3_2024_03_02.txt"; // 読み込みたいファイルの名前
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "ファイルを開けませんでした: " << fileName << std::endl;
        return 1; // エラー終了
    }

    std::string fileLine;
    std::getline(file, fileLine);
    file.close();

    // 区切り文字で分割
    std::vector<std::string> emailList;
    std::stringstream ss(fileLine);
    std::string schoolNumber;
    while (std::getline(ss, schoolNumber, ',')) {
        emailList.push_back(schoolNumber);
    }

    // []を除外
    std::string target = "[";
    for (auto& number : emailList) {
        number.erase(std::remove(number.begin(), number.end(), target[0]), number.end());
    }

    target = "]";
    for (auto& number : emailList) {
        number.erase(std::remove(number.begin(), number.end(), target[0]), number.end());
    }

    // ソート
    std::sort(emailList.begin(), emailList.end(), [](const std::string& fileA, const std::string& fileB) {
        return extractKey(fileA) < extractKey(fileB);
              });

    for (const auto& email : emailList) {
        std::cout << email << std::endl;
    }

	return 0;
}