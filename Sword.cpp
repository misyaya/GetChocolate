#include "Sword.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

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

    SphereCollider* collisionS = new SphereCollider(XMFLOAT3(0.5f, 2.0f, 0.8f), 1.2f);
    AddCollider(collisionS);
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