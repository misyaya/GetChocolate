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
    PlayerChase();
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

void Enemy::SetEnemyPos(XMFLOAT3 _enemyPos)
{
    enemyTr.position_ = _enemyPos;
}

XMFLOAT3 Enemy::GetEnemyPos()
{
    return transform_.position_;
}


void Enemy::PlayerChase()
{
    // �v���C���[�̈ʒu�����擾���A�G�l�~�[�̈ʒu���X�V����
    XMFLOAT3 plPos = pl->GetPlayerPos(); // �v���C���[�̈ʒu���擾
    SetEnemyPos(plPos); // �G�l�~�[�̈ʒu���v���C���[�̈ʒu�ɍX�V
}

