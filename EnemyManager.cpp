#include "EnemyManager.h"

EnemyManager::EnemyManager()
	:enemyDead_(0)
{
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::SetDeadCount(int _count)
{
	enemyDead_ = enemyDead_ + _count;
}

int EnemyManager::GetDeadCount()
{
	return enemyDead_;
}
