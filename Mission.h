#pragma once
#include <string>

using std::string;

// �~�b�V�����̏��
enum MissionStatus 
{
    NotStarted,
    InProgress,
    Completed
};

//�~�b�V����
struct Mission
{
    string name;
    MissionStatus status;

    //�R���X�g���N�^
    Mission(const string& missionName);
};