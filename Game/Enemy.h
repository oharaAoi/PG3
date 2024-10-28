#pragma once

enum class Behavior {
	Approach_State,
	Attack_State,
	Left_State,
};

class Enemy {
public:

	Enemy();
	~Enemy();

	void Init();

	void Action();

	void Approach();

	void Attack();

	void Left();

	void SetEnemyState(const Behavior state) { state_ = state; }

private:

	// メンバ関数ポインタのテーブル
	static void(Enemy::* ChangeState[])();
		
	Behavior state_;

};

