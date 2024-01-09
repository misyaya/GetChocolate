#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Player.h"


//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"), enemy_(-1),enemySpeed_(0.005)
{
    pl = new Player(parent);
    enemyTr.position_ = XMFLOAT3(3.0f, 0.0f, 60.0f);
}

//�f�X�g���N�^
Enemy::~Enemy()
{
    delete pl;
}

//������
void Enemy::Initialize()
{
    //���f���f�[�^�̃��[�h
    enemy_ = Model::Load("Enemy.fbx");
    assert(enemy_ >= 0);

  /*  enemyTr.position_.x = 3.0f;
    enemyTr.position_.z = 3.0f;*/

    SphereCollider* collision = new SphereCollider(XMFLOAT3(enemyTr.position_.x, 1.3f, enemyTr.position_.z), 1.2f);
    AddCollider(collision);
}

//�X�V
void Enemy::Update()
{
    
}

//�`��
void Enemy::Draw()
{
    Model::SetTransform(enemy_, enemyTr);
    Model::Draw(enemy_);
}

//�J��
void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
}

