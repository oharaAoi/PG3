#include <stdio.h>
#include <iostream>
#include <windows.h>
#include "Game/Enemy.h"

//==================================================================================
// ↓　関数群
//==================================================================================

typedef void (*FunctionPtr)(int*);

void Wait(int* s) {
	printf("%d秒行動しました\n", *s);
}

void SetTimeout(FunctionPtr ptr, int second) {
	Sleep(second * 1000);
	ptr(&second);
}


//==================================================================================
// ↓　
//==================================================================================

int main() {

	// -------------------------------------------------
	// ↓ 初期化の処理
	// -------------------------------------------------
	Enemy enemy_;
	enemy_.Init();

	FunctionPtr ptr;
	ptr = Wait;

	// -------------------------------------------------
	// ↓ 更新の処理
	// -------------------------------------------------
	printf("開始!\n");

	enemy_.Action();
	SetTimeout(ptr, 1);
	
	enemy_.SetEnemyState(Behavior::Attack_State);
	enemy_.Action();
	SetTimeout(ptr, 1);

	enemy_.SetEnemyState(Behavior::Left_State);
	enemy_.Action();

	printf("終了!\n");
	
	return 0;
}