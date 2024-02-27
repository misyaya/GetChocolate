#include "Mission.h"
#include <iostream>



Mission::Mission(const string& name, const string& description)
{
}

void Mission::UpdateStatus(MissionStatus newStatus)
{
	status_ = newStatus;
}

void Mission::DefeatEnemy()
{

}

string Mission::GetMissionType() const
{
	return "Defeat Enemies";
}

const string& Mission::GetName() const
{
	return name_;
}

string Mission::GetStatusString() const
{
	return string();
}
