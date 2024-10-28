#include "Enemy.h"
#include <stdio.h>

Enemy::Enemy() {}
Enemy::~Enemy() {}

void Enemy::Init() {
	state_ = Behavior::Approach_State;
}

void Enemy::Action() {
	(this->*ChangeState[static_cast<size_t>(state_)])();
}

void Enemy::Approach() {
	printf("接近中!\n");
}

void Enemy::Attack() {
	printf("攻撃!\n");
}

void Enemy::Left() {
	printf("離脱!\n");
}

void (Enemy::* Enemy::ChangeState[])() = {
		&Enemy::Approach,
		&Enemy::Attack,
		&Enemy::Left,
};