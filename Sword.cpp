#include "Sword.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Sword::Sword(GameObject* parent)
    :GameObject(parent, "Sword"), sword_(-1)
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
    sword_ = Model::Load("Sword.fbx");
    assert(sword_ >= 0);

    transform_.position_.x = 0.5f;
    transform_.position_.y = 2.0f;
    transform_.position_.z = 0.8f;
    state_ = ATTACK;
}

//�X�V
void Sword::Update()
{
    //�G���^�[�������ꂽ��
    if (Input::IsKeyDown(DIK_RETURN) )
    {
        transform_.rotate_.z = 0.0f;
        transform_.rotate_.x = 0.0f;
        
        ClearCollider();

    }
    if (Input::IsKeyDown(DIK_UP)&& attackflag_)
    {
        BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 1, 1), XMFLOAT3(1, 1, 1));
        AddCollider(collision);

     
        AttackBeside();
    }
   
    //�X�y�[�X�L�[��������Ă�����
    if (Input::IsKeyDown(DIK_SPACE))
    {
        flag_ = true;
        AttackSword();  
    }

    //�G���^�[�������ꂽ��
    if (Input::IsKey(DIK_L))
    {
        transform_.rotate_.x += 10.0f;
    }

    if (Input::IsKey(DIK_K))
    {
        float rotationSpeed = 0.5f;
        while(atF)
        {
            if (transform_.rotate_.x < 90.0f && attackflag_)
            {
                transform_.rotate_.x += rotationSpeed;
            }
            else
            {
                // ��]��90�x�𒴂����ꍇ�A90�x�ɌŒ�

                attackflag_ = false;
                // 90�x�܂ŉ�]������A0�x�܂Ŗ߂�
                if (transform_.rotate_.x > 0.0f)
                {
                    transform_.rotate_.x -= rotationSpeed;
                }
                else
                {
                    // ��]��0�x�𒴂����ꍇ�A0�x�ɌŒ�
                    transform_.rotate_.x = 0.0f;
                    atF = false;
                }
            }
        }
    }
    //ClearCollider();
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
        flag_ = false;
    }
}

void Sword::SetSwordTr(XMFLOAT3 _transform)
{
    transform_.position_ = _transform;
}

void Sword::AttackSword()
{
    if(flag_)
    {
        BoxCollider* collision = new BoxCollider(XMFLOAT3(transform_.position_.x, 0, transform_.position_.z), XMFLOAT3(1, 1, 1));
        AddCollider(collision);
    }

    while(transform_.rotate_.x <= 120.0f)
    {
        transform_.rotate_.x += 10.0f;
    }
}

void Sword::AttackBeside()
{
    attackflag_ = false;

    while (transform_.rotate_.z <= 100)
    {
        transform_.rotate_.z += 0.5f;
    }

    while (transform_.rotate_.z >= -100)
    {
        transform_.rotate_.z -= 0.5f;
    }
 
    attackflag_ = true;
}
