#pragma once
#include "Engine/GameObject.h"

//�^�C�g���w�i���Ǘ�����N���X
class Title_Back : public GameObject
{
    int hBack_;    //�w�i

    Transform backTr_;

public:
    //�R���X�g���N�^
    Title_Back(GameObject* parent);

    //�f�X�g���N�^
    ~Title_Back();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};