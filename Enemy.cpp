#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Player.h"


//コンストラクタ
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"), enemy_(-1),enemySpeed_(0.05),pl(nullptr), playerPos_(0.0f, 0.0f, 0.0f),
    differenceX(0), differenceY(0), differenceZ(0)
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

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 1.2f, 0), 1.0f);
    AddCollider(collision);
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
       // KillMe();
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
    //エネミー位置とプレイヤー位置の差
    differenceX = transform_.position_.x - playerPos_.x;
    //differenceY = transform_.position_.y - playerPos_.y;
    differenceZ = transform_.position_.z - playerPos_.z;

    float chaseDistance = 10.0f; // PlayerとEnemy距離

    if (abs(differenceX) < chaseDistance &&
        abs(differenceY) < chaseDistance &&
        abs(differenceZ) < chaseDistance)
    {
        //進む方向　X
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

        //進む方向　Z
        if (abs(differenceZ) > 0.2f)
        {
            if (differenceZ > 0.2f)
            {
                transform_.position_.z -= enemySpeed_;
            }
            else if (differenceZ < -0.2f)
            {
                transform_.position_.z += enemySpeed_;
            }
        }
    }
   
}


