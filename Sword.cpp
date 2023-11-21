#include "Sword.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

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

    
}

//�X�V
void Sword::Update()
{
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