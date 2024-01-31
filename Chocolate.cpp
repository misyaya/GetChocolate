#include "Chocolate.h"
#include "Engine/Model.h"


//�R���X�g���N�^
Chocolate::Chocolate(GameObject* parent)
    :GameObject(parent, "Chocolate"), hChoco_(-1)
{
}

//�f�X�g���N�^
Chocolate::~Chocolate()
{
}

//������
void Chocolate::Initialize()
{
    //���f���f�[�^�̃��[�h
    hChoco_ = Model::Load("Chocolate.fbx");
    assert(hChoco_ >= 0);

    transform_.position_.x = 2.0f;
    transform_.position_.y = 1.0f;
    transform_.position_.z = 3.0f;
}

//�X�V
void Chocolate::Update()
{
    transform_.rotate_.y += 1.0f;
}

//�`��
void Chocolate::Draw()
{
    Model::SetTransform(hChoco_, transform_);
    Model::Draw(hChoco_);
}

//�J��
void Chocolate::Release()
{
}