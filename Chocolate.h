#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Chocolate : public GameObject
{
    int hChoco_;

public:
    //�R���X�g���N�^
    Chocolate(GameObject* parent);

    //�f�X�g���N�^
    ~Chocolate();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};