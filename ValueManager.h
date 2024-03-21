#pragma once

//複数のシーンで使う値管理
class ValueManager
{
private:
	int points_;
	int enemyDead_;

	//プライベートコンストラクタ
	ValueManager() : points_(0), enemyDead_ (0){}

public:
	static ValueManager& GetInstance();
	void AddPoints(int _amount);
	int GetPoints() const;
	void ResetPoints();

	void AddEnemyD(int _amount);
	int GetEnemyD() const;
	void ResetEnemyD();


};