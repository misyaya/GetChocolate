#pragma once
#include "Engine/GameObject.h"

//�~�b�V�����\�����Ǘ�����N���X
class MissionDisplay : public GameObject
{

public:
    //�R���X�g���N�^
    MissionDisplay(GameObject* parent);

    //�f�X�g���N�^
    ~MissionDisplay();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};