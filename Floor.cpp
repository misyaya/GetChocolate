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