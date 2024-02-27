#pragma once
#include <string>

using std::string;

//ミッションを管理するクラス
class Mission
{
    enum MissionStatus {
        NotStarted,
        InProgress,
        Completed
    };

    string name_;
    string description_;
    MissionStatus status_;
    int requiredEnemyCount;
    int enemyCount;

    string GetStatusString() const;

public:
    //コンストラクタ
    Mission(const string& name, const string& description);
    
    //ステータス更新
    void UpdateStatus(MissionStatus newStatus);

    void DefeatEnemy();

    string GetMissionType() const;

    const string& GetName() const;
};