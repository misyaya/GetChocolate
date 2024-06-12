#include "Trap.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

//�R���X�g���N�^
Trap::Trap(GameObject* parent)
    :GameObject(parent, "Trap"), hTrap_(-1), speed_(3.0f), movingUp_(true)
{
}

//�f�X�g���N�^
Trap::~Trap()
{
}

//������
void Trap::Initialize()
{
    //���f���f�[�^�̃��[�h
    hTrap_ = Model::Load("Fbx/trap.fbx");
    assert(hTrap_ >= 0);
    transform_.scale_ = XMFLOAT3(0.3f, 0.5f, 0.3f);
    transform_.rotate_.y = 90.0f;
    transform_.position_ = XMFLOAT3(20.0f, -7.0f, 30.0f);


    BoxCollider* collision = new BoxCollider(XMFLOAT3(0.0f, 3.0f, 0.0f), XMFLOAT3(0.7f, 2.0f, 1.0f));
    AddCollider(collision);
}

//�X�V
void Trap::Update()
{
    if (movingUp_)
    {
        transform_.position_.y += speed_ * 0.016f;

        if (transform_.position_.y >= -0.5f) {
            transform_.position_.y = -0.5f;
            movingUp_ = false;
        }
    }
    else
    {
        transform_.position_.y -= speed_ * 0.016f;
        
        if (transform_.position_.y <= -5.0f) {
            transform_.position_.y = -5.0f;
            movingUp_ = true;
        }
    }
}

//�`��
void Trap::Draw()
{
    Model::SetTransform(hTrap_, transform_);
    Model::Draw(hTrap_);
}

//�J��
void Trap::Release()
{
}