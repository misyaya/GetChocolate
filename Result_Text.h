#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//���U���g�̃e�L�X�g�\�������Ǘ�����N���X
class Result_Text : public GameObject
{
    //�e��l
    int chocoPoint_; //Chocolate���l��������
    int enemyPoint_; //Enemy��|������

    //�e�L�X�g�\��
    Text* pTextE; //EN�̕����\��
    Text* pEnemy; //enemyPoint_�\��

    Text* pTextC; //CH�̕����\��
    Text* pChoco; //chocoPoint_�\��

public:
    //�R���X�g���N�^
    Result_Text(GameObject* parent);

    //�f�X�g���N�^
    ~Result_Text();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};