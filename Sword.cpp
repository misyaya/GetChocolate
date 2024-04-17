#include "Sword.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Audio.h"

//�R���X�g���N�^
Sword::Sword(GameObject* parent)
    :GameObject(parent, "Sword"), sword_(-1),sSword_(-1)
{
}

//�f�X�g���N�^
Sword::~Sword()
{
}

//������
void Sword::Initialize()
{
    //���f���f�[�^�̃��[�h
    sword_ = Model::Load("Fbx/Sword.fbx");
    assert(sword_ >= 0);

    //�T�E���h�f�[�^�̃��[�h
    //��(�U�艺�낷)
    sSword_ = Audio::Load("Sound/sword.WAV");
    assert(sSword_ >= 0);

    transform_.position_.y = 2.0f;
    transform_.position_.z = 0.7f;
    transform_.position_.x = 0.0f;

    state_ = ATTACK;
}

//�X�V
void Sword::Update()
{  
	XMFLOAT3 fMove = XMFLOAT3(0, 0, 0);


    //�X�y�[�X�L�[��������Ă�����
    if (Input::IsKeyDown(DIK_SPACE))
    {
        AttackSword();  
    }

    if (colliderFlag_ == true)
    {
        ClearCollider();
        colliderFlag_ = false;
    }
}

//�`��
void Sword::Draw()
{
    Model::SetTransform(sword_, transform_);
    Model::Draw(sword_);
}

//�J��
void Sword::Release()
{
}

//�����蔻��
void Sword::OnCollision(GameObject* pTarget)
{
    //�G�ɓ��������Ƃ�
    if (pTarget->GetObjectName() == "Enemy")
    {
        colliderFlag_ = true; 
        attackFlag_ = false;
        FinishAttack();
    }
}

void Sword::SetSwordTr(XMFLOAT3 _transform)
{
    transform_.position_ = _transform;
}

void Sword::AttackSword()
{
    if(attackFlag_ == false)
    {
        BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1));
        AddCollider(collision);

        Audio::Play(sSword_);

        while (transform_.rotate_.x <= 120.0f)
        {
            transform_.rotate_.x += 10.0f;
        }
    }

    attackFlag_ = true;
 
}


void Sword::FinishAttack()
{
    transform_.rotate_.x = 0;
}

void Sword::SetSwordPos(XMFLOAT3 _position)
{
    transform_.position_ = _position;
}

XMFLOAT3 Sword::GetSwordPos()
{
    return transform_.position_;
}

void Sword::MoveBackward(float _distance)
{
    // �v���C���[�̌��݈ʒu���擾
    XMFLOAT3 currentPosition = GetSwordPos();

    // �v���C���[�����Ɉړ�
    currentPosition.z += _distance;

    // �ړ���̈ʒu��ݒ�
    SetSwordPos(currentPosition);
}
