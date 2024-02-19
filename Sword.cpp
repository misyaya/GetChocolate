#include "Sword.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"
#include "Engine/Input.h"

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

}

//更新
void Sword::Update()
{
    //エンターが押されたら
    if (Input::IsKeyDown(DIK_RETURN) )
    {
        transform_.rotate_.z = 0.0f;
        ClearCollider();

    }

   
    //スペースキーが押されていたら
    if (Input::IsKey(DIK_SPACE))
    {
        BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 1, 1), XMFLOAT3(1, 1, 1));
        AddCollider(collision);

        AttackSword();
        //transform_.rotate_.x = 90.0f;
        state_ = ATTACK;
        
        
    }

    //if (Input::IsKey(DIK_W))
    //{
    //    transform_.position_.z += 0.1f;
    //    transform_.rotate_.y = front.rotate_.y;
    //}

    ////後
    //if (Input::IsKey(DIK_S))
    //{
    //    transform_.position_.z -= 0.1f;
    //    transform_.rotate_.y = front.rotate_.y - 180.0f;
    //}

    ////左
    //if (Input::IsKey(DIK_D))
    //{
    //    transform_.position_.x += 0.1f;
    //    transform_.rotate_.y = front.rotate_.y + 90.0f;
    //}

    ////右
    //if (Input::IsKey(DIK_A))
    //{
    //    transform_.position_.x -= 0.1f;
    //    transform_.rotate_.y = front.rotate_.y - 90.0f;
    //}
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

void Sword::AttackSword()
{
    switch (state_)
    {
    case MOVE:
        break;
    case ATTACK:
        transform_.rotate_.x += 10;
  
    }
}
