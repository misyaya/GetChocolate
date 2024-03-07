#include "MissionDisplay.h"
#include "MissionManager.h"

//�R���X�g���N�^
MissionDisplay::MissionDisplay(GameObject* parent)
    :GameObject(parent, "MissionDisplay")
{
}

//�f�X�g���N�^
MissionDisplay::~MissionDisplay()
{
}

//������
void MissionDisplay::Initialize()
{
    MissionManager manager;
    manager.AddMission("�G���R�̓|��");
    manager.AddMission("�A�C�e�����R�l������");
    manager.AddMission("�S�[������");

    manager.StartMission("�G���R�̓|��");
}

//�X�V
void MissionDisplay::Update()
{
}

//�`��
void MissionDisplay::Draw()
{
}

//�J��
void MissionDisplay::Release()
{
}