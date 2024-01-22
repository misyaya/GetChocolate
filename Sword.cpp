#include "Sword.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

//コンストラクタ
Sword::Sword(GameObject* parent)
    :GameObject(parent, "Sword"), sword_(-1)
{
}

//デストラクタ
Sword::~Sword()
{
}

//初期化
void Sword::Initialize()
{
    //モデルデータのロード
    sword_ = Model::Load("Sword.fbx");
    assert(sword_ >= 0);

    transform_.position_.x = 0.5f;
    transform_.position_.y = 2.0f;
    transform_.position_.z = 0.8f;

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 1, 1), XMFLOAT3(1, 1, 1));
    AddCollider(collision);
}

//更新
void Sword::Update()
{
}

//描画
void Sword::Draw()
{
    Model::SetTransform(sword_, transform_);
    Model::Draw(sword_);
}

//開放
void Sword::Release()
{
}

//当たり判定
void Sword::OnCollision(GameObject* pTarget)
{
    //敵に当たったとき
    if (pTarget->GetObjectName() == "Enemy")
    {

    }
}

void Sword::SetSwordTr(XMFLOAT3 _transform)
{
    transform_.position_ = _transform;
}
