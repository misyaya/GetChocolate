#pragma once
#include "Engine/GameObject.h"

//���U���g�w�i���Ǘ�����N���X
class Result_Back : public GameObject
{
    int hBack_;    //�w�i

    Transform backTr_;

public:
    //�R���X�g���N�^
    Result_Back(GameObject* parent);

    //�f�X�g���N�^
    ~Result_Back();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};