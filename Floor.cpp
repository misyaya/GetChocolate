#include "Floor.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Floor::Floor(GameObject* parent)
    :GameObject(parent, "Floor"),floor_(-1)
{
}

//�f�X�g���N�^
Floor::~Floor()
{
}

//������
void Floor::Initialize()
{
    //���f���f�[�^�̃��[�h
    floor_ = Model::Load("Floor.fbx");
    assert(floor_ >= 0);
    transform_.position_.z = 45.0f;
    transform_.scale_ = XMFLOAT3(10.0, 1.0f, 15.0f);
}

//�X�V
void Floor::Update()
{
}

//�`��
void Floor::Draw()
{
    Model::SetTransform(floor_, transform_);
    Model::Draw(floor_);
}

//�J��
void Floor::Release()
{
}