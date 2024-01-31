#include "Chocolate.h"
#include "Engine/Model.h"


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