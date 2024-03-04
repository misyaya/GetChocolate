#pragma once
#include "Engine/GameObject.h"

//�X�e�[�W�����Ǘ�����N���X
class Floor : public GameObject
{
    int floor_;
public:
    //�R���X�g���N�^
    Floor(GameObject* parent);

    //�f�X�g���N�^
    ~Floor();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};