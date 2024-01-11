#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Player.h"


//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"), enemy_(-1),enemySpeed_(0.005)
{
}

//�f�X�g���N�^
Enemy::~Enemy()
{
}

//������
void Enemy::Initialize()
{
    //���f���f�[�^�̃��[�h
    enemy_ = Model::Load("Enemy.fbx");
    assert(enemy_ >= 0);

    transform_.position_ = XMFLOAT3(2.0, 0.0f, 6.0f);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0,1.2f,0), 1.2f);
    AddCollider(collision);
}

//�X�V
void Enemy::Update()
{
    
}

//�`��
void Enemy::Draw()
{
    Model::SetTransform(enemy_, transform_);
    Model::Draw(enemy_);
}

//�J��
void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
    //�G�ɓ��������Ƃ�
    if (pTarget->GetObjectName() == "Sword")
    {
        KillMe();
    }
}


