#include "Chocolate.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

//コンストラクタ
Chocolate::Chocolate(GameObject* parent)
    :GameObject(parent, "Chocolate"), hChoco_(-1)
{
}

//デストラクタ
Chocolate::~Chocolate()
{
}

//初期化
void Chocolate::Initialize()
{
    //モデルデータのロード
    hChoco_ = Model::Load("Chocolate.fbx");
    assert(hChoco_ >= 0);

    transform_.position_.x = 2.0f;
    transform_.position_.y = 1.0f;
    transform_.position_.z = 3.0f;

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1));
    AddCollider(collision);
}

//更新
void Chocolate::Update()
{
    transform_.rotate_.y += 1.0f;
}

//描画
void Chocolate::Draw()
{
    Model::SetTransform(hChoco_, transform_);
    Model::Draw(hChoco_);
}

//開放
void Chocolate::Release()
{
}

//何かに当たった
void Chocolate::OnCollision(GameObject* pTarget)
{
    //プレイヤーに当たったとき
    if (pTarget->GetObjectName() == "Player")
    {
        KillMe();
    }
}