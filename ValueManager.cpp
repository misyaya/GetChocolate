#include "ValueManager.h"

ValueManager& ValueManager::GetInstance()
{
    static ValueManager instance;
    return instance;
}

void ValueManager::AddPoints(int _amount)
{
    points_ += _amount;
}

int ValueManager::GetPoints() const
{
    return points_;
}

void ValueManager::ResetPoints()
{
    points_ = 0;
}

void ValueManager::AddEnemyD(int _amount)
{
    enemyDead_ += _amount;
}

int ValueManager::GetEnemyD() const
{
    return enemyDead_;
}

void ValueManager::ResetEnemyD()
{
    enemyDead_ = 0;
}
