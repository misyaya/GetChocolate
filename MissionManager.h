#pragma once
#include <iostream>
#include <vector>
#include "Mission.h"

using std::vector;

//�~�b�V�������Ǘ�����N���X
class MissionManager
{
private:
	vector<Mission>missions;

public:
	//�R���X�g���N�^
	MissionManager();

	//�f�X�g���N�^
	~MissionManager();

	//�~�b�V�����̒ǉ�
	void AddMission(const string& _missionName);

	//�~�b�V�����̏�Ԋm�F
	MissionStatus GetMissionStatus(const string& _missionName) const;

	//�~�b�V�����J�n
	void StartMission(const string& _missionName);

	//�~�b�V�����I��
	void FinishMission(const string& _missionName);

	void EnemyCheck();

};

