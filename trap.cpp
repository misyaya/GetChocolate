#include "Trap.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Trap::Trap(GameObject* parent)
    :GameObject(parent, "Trap"), hTrap_(-1)
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
}

//�X�V
void Trap::Update()
{
}

//�`��
void Trap::Draw()
{
    transform_.position_ = XMFLOAT3(10.0f, 2.0f, 30.0f);
    Model::SetTransform(hTrap_, transform_);
    Model::Draw(hTrap_);
}

//�J��
void Trap::Release()
{
}