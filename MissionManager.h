#pragma once
#include <iostream>
#include <vector>
#include "Mission.h"

using std::vector;

//ミッションを管理するクラス
class MissionManager
{
private:
	vector<Mission>missions;

public:
	//コンストラクタ
	MissionManager();

	//デストラクタ
	~MissionManager();

	//ミッションの追加
	void AddMission(const string& _missionName);

	//ミッションの状態確認
	MissionStatus GetMissionStatus(const string& _missionName) const;

	//ミッション開始
	void StartMission(const string& _missionName);

	//ミッション終了
	void FinishMission(const string& _missionName);

	void EnemyCheck();

};

