#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class StartButton : public GameObject
{
    int hButton_;  //�{�^��

    Transform buttonTr_;

public:
    //�R���X�g���N�^
    StartButton(GameObject* parent);

    //�f�X�g���N�^
    ~StartButton();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};