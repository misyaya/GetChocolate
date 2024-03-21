#pragma once

//�����̃V�[���Ŏg���l�Ǘ�
class ValueManager
{
private:
	int points_;
	int enemyDead_;

	//�v���C�x�[�g�R���X�g���N�^
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