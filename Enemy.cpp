#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"


//コンストラクタ
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"), enemy_(-1),enemySpeed_(0.5)
{
}

//デストラクタ
Enemy::~Enemy()
{
}

//初期化
void Enemy::Initialize()
{
    //モデルデータのロード
    enemy_ = Model::Load("Enemy.fbx");
    assert(enemy_ >= 0);

    enemyTr.position_.x = 3.0f;
    enemyTr.position_.z = 3.0f;

    SphereCollider* collision = new SphereCollider(XMFLOAT3(enemyTr.position_.x, 1.3f, enemyTr.position_.z), 1.2f);
    AddCollider(collision);
}

//更新
void Enemy::Update()
{
    ChasePlayer();
}

//描画
void Enemy::Draw()
{
    Model::SetTransform(enemy_, enemyTr);
    Model::Draw(enemy_);
}

//開放
void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
}

void Enemy::SetEnemyTr(Transform _transform)
{
    enemyTr = _transform;
}

Transform Enemy::GetEnemyTr()
{
    return enemyTr;
}

void Enemy::ChasePlayer()
{
    player = pl->GetPlayerTr();
    plX = player.x;
    plY = player.y;
    plZ = player.z;

    if (plX > enemyTr.position_.x)
    {
        enemyTr.position_.x += enemySpeed_;
    }
    else
    {
        enemyTr.position_.x -= enemySpeed_;
    }

    if (plY > enemyTr.position_.y)
    {
        enemyTr.position_.y += enemySpeed_;
    }
    else
    {
        enemyTr.position_.y-= enemySpeed_;
    }

    if (plX > enemyTr.position_.z)
    {
        enemyTr.position_.z += enemySpeed_;
    }
    else
    {
        enemyTr.position_.z -= enemySpeed_;
    }
}
