#pragma once
#include "Engine/GameObject.h"

//�؂��Ǘ�����N���X
class Tree : public GameObject
{
    //���f��
    int hTree_;

public:
    //�R���X�g���N�^
    Tree(GameObject* parent);

    //�f�X�g���N�^
    ~Tree();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};