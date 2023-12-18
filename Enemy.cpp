#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Player.h"


//コンストラクタ
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"), enemy_(-1),enemySpeed_(0.005)
{
    pl = new Player(parent);
    enemyTr.position_ = XMFLOAT3(3.0f, 0.0f, 60.0f);
}

//デストラクタ
Enemy::~Enemy()
{
    delete pl;
}

//初期化
void Enemy::Initialize()
{
    //モデルデータのロード
    enemy_ = Model::Load("Enemy.fbx");
    assert(enemy_ >= 0);

  /*  enemyTr.position_.x = 3.0f;
    enemyTr.position_.z = 3.0f;*/

    SphereCollider* collision = new SphereCollider(XMFLOAT3(enemyTr.position_.x, 1.3f, enemyTr.position_.z), 1.2f);
    AddCollider(collision);
}

//更新
void Enemy::Update()
{
    PlayerChase();
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
    // プレイヤーの位置情報を取得し、エネミーの位置を更新する
    XMFLOAT3 plPos = pl->GetPlayerPos(); // プレイヤーの位置を取得
    SetEnemyPos(plPos); // エネミーの位置をプレイヤーの位置に更新
}

