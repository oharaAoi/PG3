#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <windows.h>

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓　関数群
//////////////////////////////////////////////////////////////////////////////////////////////////

typedef void (*FunctionPtr)(int*);

void StandBy(int* s) {
	printf("%d秒待ちました\n", *s);
}

void SetTimeout(FunctionPtr ptr, int second) {
	Sleep(second * 1000);
	ptr(&second);
}

void Verification(const int& input, const int& result) {
	if (input % 2 == result % 2) {
		printf("正解");
	} else {
		printf("不正解");
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓ main処理
//////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	srand((unsigned int)time(nullptr));

	// 入力の受付
	int input;
	printf("偶数か奇数を選んでください(偶数 : 0, 奇数 : 1)\n");
	std::cin >> input;

	// 0か1以外なら
	while (input != 0 && input != 1) {
		printf("0か1かを選んでください\n");
		std::cin >> input;
	}
	
	// 関数ポインタを設定
	FunctionPtr ptr;
	ptr = StandBy;
	// 実行(関数のポインタを引数に渡す)
	SetTimeout(ptr, 3);

	// 結果の表示
	int random = (rand() % 6) + 1;
	printf("出た目は%d\n", random);
	Verification(input, random);

	return 0;
}