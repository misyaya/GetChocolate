#pragma once
#include <string>

using std::string;

// ミッションの状態
enum MissionStatus 
{
    NotStarted,
    InProgress,
    Completed
};

//ミッション
struct Mission
{
    string name;
    MissionStatus status;

    //コンストラクタ
    Mission(const string& missionName);
};