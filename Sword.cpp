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
        ClearCollider();

    }
    if (Input::IsKeyDown(DIK_UP)&& attackflag_)
    {
        BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 1, 1), XMFLOAT3(1, 1, 1));
        AddCollider(collision);

     
        AttackBeside();
    }
   
    //�X�y�[�X�L�[��������Ă�����
    if (Input::IsKey(DIK_SPACE)&& attackflag_)
    {
        BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 1, 1), XMFLOAT3(1, 1, 1));
        AddCollider(collision);

        AttackSword();  
    }

    //if (Input::IsKey(DIK_W))
    //{
    //    transform_.position_.z += 0.1f;
    //    transform_.rotate_.y = front.rotate_.y;
    //}

    ////��
    //if (Input::IsKey(DIK_S))
    //{
    //    transform_.position_.z -= 0.1f;
    //    transform_.rotate_.y = front.rotate_.y - 180.0f;
    //}

    ////��
    //if (Input::IsKey(DIK_D))
    //{
    //    transform_.position_.x += 0.1f;
    //    transform_.rotate_.y = front.rotate_.y + 90.0f;
    //}

    ////�E
    //if (Input::IsKey(DIK_A))
    //{
    //    transform_.position_.x -= 0.1f;
    //    transform_.rotate_.y = front.rotate_.y - 90.0f;
    //}
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

    }
}

void Sword::SetSwordTr(XMFLOAT3 _transform)
{
    transform_.position_ = _transform;
}

void Sword::AttackSword()
{
    attackflag_ = false;
    switch (state_)
    {
    case MOVE:
        break;
    case ATTACK:
        transform_.rotate_.x += 20;
        if(transform_.rotate_.x >= 100)
        {
            state_ = RETURN;
            break;
        }
        state_ = ATTACK;
    case RETURN:
        transform_.rotate_.x -= 10;
        if (transform_.rotate_.x <= 0)
        {
            state_ = ATTACK;
            attackflag_ = true;
            break;
        }
    }
}

void Sword::AttackBeside()
{
    attackflag_ = false;
    switch (state_)
    {
    case MOVE:
        break;
    case ATTACK:
        while (transform_.rotate_.z <= 100)
        {
            transform_.rotate_.z += 0.5f;
        }
        state_ = RETURN;
        
    case RETURN:
        while (transform_.rotate_.z >= 0)
        {
            transform_.rotate_.z -= 10;
            
        }
        state_ = ATTACK;
        attackflag_ = true;
        break;
    }
}
