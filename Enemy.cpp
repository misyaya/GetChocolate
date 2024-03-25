#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Player.h"
#include "Chocolate.h"
#include "Engine/Audio.h"
#include "ValueManager.h"


//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"), enemy_(-1),enemySpeed_(0.05),pl(nullptr), playerPos_(0.0f, 0.0f, 0.0f),
    differenceX(0), differenceY(0), differenceZ(0), sDead_(-1), sChase_(-1)
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

    transform_.position_.x = (float)(rand() % 30 + 10 );
    transform_.position_.z = (float)(rand() % 55 + 4 );

    transform_.scale_ = XMFLOAT3(1.5f, 1.5f, 1.5f);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 1.2f, 0), 1.0f);
    AddCollider(collision);

    //�T�E���h�f�[�^�̃��[�h
    sDead_ = Audio::Load("enemyDead.wav");
    assert(sDead_ >= 0);

    sChase_ = Audio::Load("enemyChase.wav");
    assert(sChase_ >= 0);
}

//�X�V
void Enemy::Update()
{
    if (pl)
    {
        playerPos_ = pl->GetPosition();
        PlayerChase();
    }
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
    //���ɓ��������Ƃ�
    if (pTarget->GetObjectName() == "Sword")
    {
        ValueManager::GetInstance().AddEnemyD(1);
        Audio::Play(sDead_);
        Audio::Stop(sChase_);
        KillMe();
    }
}

void Enemy::SetPlayer(Player* player)
{
    pl = player;
}

void Enemy::SetPlayerPos(XMFLOAT3 _playerPos)
{
    transform_.position_ = _playerPos;
}

void Enemy::PlayerChase()
{
    //�G�l�~�[�ʒu�ƃv���C���[�ʒu�̍�
    differenceX = transform_.position_.x - playerPos_.x;
    //differenceY = transform_.position_.y - playerPos_.y;
    differenceZ = transform_.position_.z - playerPos_.z;

    float chaseDistance = 10.0f; // Player��Enemy����

    if (abs(differenceX) < chaseDistance &&
        abs(differenceY) < chaseDistance &&
        abs(differenceZ) < chaseDistance)
    {
        Audio::Play(sChase_);
        //�i�ޕ����@X
        if (abs(differenceX) > 0.2f)
        {
            if (differenceX > 0.2f)
            {
                transform_.position_.x -= enemySpeed_;
            }
            else if (differenceX < -0.2f)
            {
                transform_.position_.x += enemySpeed_;
            }
        }

        //�i�ޕ����@Z
        if (abs(differenceZ) > 0.5f)
        {
            if (differenceZ > 0.5f)
            {
                transform_.position_.z -= enemySpeed_;
            }
            else if (differenceZ < -0.5f)
            {
                transform_.position_.z += enemySpeed_;
            }
        }
    }
    else
    {
        Audio::Stop(sChase_);
    }
   
}

void Enemy::SetEnemyPos(XMFLOAT3 _enemyPos)
{
    transform_.position_ = _enemyPos;
}


