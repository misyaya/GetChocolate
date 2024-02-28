#include "MissionManager.h"
#include "Enemy.h"

MissionManager::MissionManager()
{
}

MissionManager::~MissionManager()
{
}

void MissionManager::AddMission(const string& _missionName)
{
	Mission newMission(_missionName);
	missions.push_back(newMission);
}

MissionStatus MissionManager::GetMissionStatus(const string& _missionName) const
{
	for (const Mission& mission : missions)
	{
		if (mission.name == _missionName)
		{
			return mission.status;
		}
	}

	return NotStarted;
}

void MissionManager::StartMission(const string& _missionName)
{
	for (Mission& mission : missions)
	{
		if (mission.name == _missionName)
		{
			mission.status = InProgress;
			return;
		}
	}
}

void MissionManager::FinishMission(const string& _missionName)
{
	for (Mission& mission : missions)
	{
		if (mission.name == _missionName)
		{
			mission.status = Completed;
			return;
		}
	}
}

void MissionManager::EnemyCheck()
{
	Enemy* enemy;

	int enKill = enemy->GetKill();

	//if(enKill >= 3 && )

}
