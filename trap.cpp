#include "Trap.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Trap::Trap(GameObject* parent)
    :GameObject(parent, "Trap"), hTrap_(-1), speed_(1.0f), movingUp_(true)
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
    transform_.scale_ = XMFLOAT3(0.3f, 0.3f, 0.3f);
    transform_.rotate_.y = 90.0f;
    transform_.position_ = XMFLOAT3(10.0f, 0.0f, 30.0f);
}

//�X�V
void Trap::Update()
{
    //switch (state_)
    //{
    //case WAIT:
    //    transform_.position_.y = 0;;
    //case UP:
    //    transform_.position_.y += 0.2;
    //    break;
    //case DOWN:
    //    transform_.position_.y -= 0.2;
    //    break;
    //}


    if (movingUp_)
    {

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