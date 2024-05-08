#include "Trap.h"
#include "Engine/Model.h"

//コンストラクタ
Trap::Trap(GameObject* parent)
    :GameObject(parent, "Trap"), hTrap_(-1)
{
}

//デストラクタ
Trap::~Trap()
{
}

//初期化
void Trap::Initialize()
{
    //モデルデータのロード
    hTrap_ = Model::Load("Fbx/trap.fbx");
    assert(hTrap_ >= 0);
}

//更新
void Trap::Update()
{
}

//描画
void Trap::Draw()
{
    transform_.position_ = XMFLOAT3(10.0f, 2.0f, 30.0f);
    Model::SetTransform(hTrap_, transform_);
    Model::Draw(hTrap_);
}

//開放
void Trap::Release()
{
}