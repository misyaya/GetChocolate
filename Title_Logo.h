#pragma once
#include "Engine/GameObject.h"

//�^�C�g�����S���Ǘ�����N���X
class Title_Logo : public GameObject
{
    int hLogo_;   //�^�C�g�����S

    Transform logoTr_;

public:
    //�R���X�g���N�^
    Title_Logo(GameObject* parent);

    //�f�X�g���N�^
    ~Title_Logo();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};