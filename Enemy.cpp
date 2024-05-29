#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Player.h"
#include "Chocolate.h"
#include "Engine/Audio.h"
#include "ValueManager.h"


//コンストラクタ
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"), enemy_(-1),enemySpeed_(0.05),pl(nullptr), playerPos_(0.0f, 0.0f, 0.0f),
    differenceX(0), differenceY(0), differenceZ(0), sDead_(-1), sChase_(-1)
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
    enemy_ = Model::Load("Fbx/Enemy.fbx");
    assert(enemy_ >= 0);

    transform_.position_.x = (float)(rand() % 30 + 10 );
    transform_.position_.z = (float)(rand() % 55 + 4 );

    transform_.scale_ = XMFLOAT3(1.5f, 1.5f, 1.5f);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 1.2f, 0), 1.0f);
    AddCollider(collision);

    //サウンドデータのロード
    sDead_ = Audio::Load("Sound/enemyDead.wav");
    assert(sDead_ >= 0);

    sChase_ = Audio::Load("Sound/enemyChase.wav");
    assert(sChase_ >= 0);
}

//更新
void Enemy::Update()
{
    if (pl)
    {
        playerPos_ = pl->GetPosition();
        PlayerChase();
    }
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
    //剣に当たったとき
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

void Enemy::PlayerChase()
{
    //ベクトルに変換
    XMVECTOR playerVec = XMLoadFloat3(&playerPos_);
    XMVECTOR enemyVec = XMLoadFloat3(&transform_.position_);

    //エネミー位置とプレイヤー位置の差
    XMVECTOR diff = XMVectorSubtract(playerVec, enemyVec);
    float distance = XMVectorGetX(XMVector3Length(diff));
    
    //PlayerとEnemy距離
    float chaseDistance = 10.0f; 

    if (distance <= 10.0f)
    {
        Audio::Play(sChase_);
  
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


