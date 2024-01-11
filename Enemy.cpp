#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Player.h"


//コンストラクタ
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"), enemy_(-1),enemySpeed_(0.005)
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

    transform_.position_ = XMFLOAT3(2.0, 0.0f, 6.0f);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0,1.2f,0), 1.2f);
    AddCollider(collision);
}

//更新
void Enemy::Update()
{
    
}

//描画
void Enemy::Draw()
{
    Model::SetTransform(enemy_, transform_);
    Model::Draw(enemy_);
}

//開放
void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
    //敵に当たったとき
    if (pTarget->GetObjectName() == "Sword")
    {
        KillMe();
    }
}


