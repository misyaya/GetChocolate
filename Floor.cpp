#include "Floor.h"
#include "Engine/Model.h"

//コンストラクタ
Floor::Floor(GameObject* parent)
    :GameObject(parent, "Floor"),floor_(-1)
{
}

//デストラクタ
Floor::~Floor()
{
}

//初期化
void Floor::Initialize()
{
    //モデルデータのロード
    floor_ = Model::Load("Floor.fbx");
    assert(floor_ >= 0);
    transform_.position_.z = 45.0f;
    transform_.scale_ = XMFLOAT3(10.0, 1.0f, 15.0f);
}

//更新
void Floor::Update()
{
}

//描画
void Floor::Draw()
{
    Model::SetTransform(floor_, transform_);
    Model::Draw(floor_);
}

//開放
void Floor::Release()
{
}