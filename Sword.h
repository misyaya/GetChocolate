#pragma once
#include "Engine/GameObject.h"

//Sword���Ǘ�����N���X
class Sword : public GameObject
{
    //���f��
    int sword_;

    Transform front;
    int state_;
   

    //�����蔻��̃t���O
    bool colliderFlag_ = false;
    bool attackFlag_ = false;


    //�T�E���h
    //��(�U�艺�낷)
    int sSword_;

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

    //�U��1
    void AttackSword();

    //�U���I��1
    void FinishAttack();

    //Sword�ʒu�̐ݒ�
    void SetSwordPos(XMFLOAT3 _position);

    //Sword�ʒu�̎擾
    XMFLOAT3 GetSwordPos();

    //���ɔ��
    void MoveBackward(float _distance);
}; 