#pragma once
#include "Engine/GameObject.h"

//Sword���Ǘ�����N���X
class Sword : public GameObject
{
    int sword_;
    Transform front;
    int state_;
    bool attackflag_ = true;
    bool flag_ = true;
    bool atF = true;
    // �N���X�̃����o�ϐ�
    bool isRotating = false;
    float targetRotation = 0.0f;
    float downSwingRotation = 90.0f;

    bool walkFlagL_ = true;
    bool walkFlagR_ = true;
    bool walkFlagF_ = true;
    bool walkFlagB_ = true;

    enum {
        MOVE = 0,
        RETURN,
        ATTACK,
        WAIT
       
    };

public:
    //�R���X�g���N�^
    Sword(GameObject* parent);

    //�f�X�g���N�^
    ~Sword();

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

    //
    void SetSwordTr(XMFLOAT3 _transform);

    void AttackSword();

    void AttackBeside();
};