#pragma once
class EnemyManager
{
	int enemyDead_;
public:
	EnemyManager();
	~EnemyManager();

	void SetDeadCount(int _count);
	int GetDeadCount();
};

