#include "Chocolate.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

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

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1));
    AddCollider(collision);
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

//�����ɓ�������
void Chocolate::OnCollision(GameObject* pTarget)
{
    //�v���C���[�ɓ��������Ƃ�
    if (pTarget->GetObjectName() == "Player")
    {
        KillMe();
    }
}