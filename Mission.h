#pragma once
#include <string>

using std::string;

//�~�b�V�������Ǘ�����N���X
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
    //�R���X�g���N�^
    Mission(const string& name, const string& description);
    
    //�X�e�[�^�X�X�V
    void UpdateStatus(MissionStatus newStatus);

    void DefeatEnemy();

    string GetMissionType() const;

    const string& GetName() const;
};