#include "Trap.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

//コンストラクタ
Trap::Trap(GameObject* parent)
    :GameObject(parent, "Trap"), hTrap_(-1), speed_(3.0f), fps_(0.016f), up_(-5.0f), down_(-0.5f), movingUp_(true)
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

    transform_.scale_ = XMFLOAT3(0.3f, 0.5f, 0.3f);
    transform_.rotate_.y = 90.0f;
    transform_.position_ = XMFLOAT3(20.0f, -7.0f, 30.0f);


    BoxCollider* collision = new BoxCollider(XMFLOAT3(0.0f, 3.0f, 0.0f), XMFLOAT3(0.7f, 2.0f, 1.0f));
    AddCollider(collision);
}

//更新
void Trap::Update()
{
    if (movingUp_)
    {
        transform_.position_.y += speed_ * fps_;

        if (transform_.position_.y >= down_) {
            transform_.position_.y = down_;
            movingUp_ = false;
        }
    }
    else
    {
        transform_.position_.y -= speed_ * fps_;
        
        if (transform_.position_.y <= up_) {
            transform_.position_.y = up_;
            movingUp_ = true;
        }
    }
}

//描画
void Trap::Draw()
{
    Model::SetTransform(hTrap_, transform_);
    Model::Draw(hTrap_);
}

//開放
void Trap::Release()
{
}