#include "Tree.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Tree::Tree(GameObject* parent)
    :GameObject(parent, "Tree"), hTree_(-1)
{
}

//�f�X�g���N�^
Tree::~Tree()
{
}

//������
void Tree::Initialize()
{
    //���f���f�[�^�̃��[�h
    hTree_ = Model::Load("Fbx/tree.fbx");
    assert(hTree_ >= 0);
}

//�X�V
void Tree::Update()
{
}

//�`��
void Tree::Draw()
{
    transform_.position_ = XMFLOAT3(10.0f, 0.0f, 10.0f);
    Model::SetTransform(hTree_, transform_);
    Model::Draw(hTree_);
}

//�J��
void Tree::Release()
{
}