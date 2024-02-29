#include "EnemyManager.h"

EnemyManager::EnemyManager()
	:enemyDead_(0)
{
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::SetEnemyDead(int _dead)
{
	enemyDead_ = _dead;
}
