#pragma once
#include "Engine/GameObject.h"
#include "Player.h"

//���������Ǘ�����N���X
class Enemy : public GameObject
{
    int enemy_;
    float enemySpeed_;
    Transform enemyTr;

    Player* pl;
    
    XMFLOAT3 playerPos_;
    float plX;
    float plY;
    float plZ;

public:
    //�R���X�g���N�^
    Enemy(GameObject* parent);

    //�f�X�g���N�^
    ~Enemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����蔻��
    void OnCollision(GameObject* pTarget);

};