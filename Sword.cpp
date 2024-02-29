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
    state_ = ATTACK;
}

//更新
void Sword::Update()
{
    //エンターが押されたら
    if (Input::IsKeyDown(DIK_RETURN) )
    {
        transform_.rotate_.z = 0.0f;
        transform_.rotate_.x = 0.0f;
        
        ClearCollider();

    }
    if (Input::IsKeyDown(DIK_UP)&& attackflag_)
    {
        BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 1, 1), XMFLOAT3(1, 1, 1));
        AddCollider(collision);

     
        AttackBeside();
    }
   
    //スペースキーが押されていたら
    if (Input::IsKeyDown(DIK_SPACE))
    {
        flag_ = true;
        AttackSword();  
    }

    //エンターが押されたら
    if (Input::IsKey(DIK_L))
    {
        transform_.rotate_.x += 10.0f;
    }

    if (Input::IsKey(DIK_K))
    {
        float rotationSpeed = 0.5f;
        while(atF)
        {
            if (transform_.rotate_.x < 90.0f && attackflag_)
            {
                transform_.rotate_.x += rotationSpeed;
            }
            else
            {
                // 回転が90度を超えた場合、90度に固定

                attackflag_ = false;
                // 90度まで回転した後、0度まで戻す
                if (transform_.rotate_.x > 0.0f)
                {
                    transform_.rotate_.x -= rotationSpeed;
                }
                else
                {
                    // 回転が0度を超えた場合、0度に固定
                    transform_.rotate_.x = 0.0f;
                    atF = false;
                }
            }
        }
    }
    //ClearCollider();
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
        flag_ = false;
    }
}

void Sword::SetSwordTr(XMFLOAT3 _transform)
{
    transform_.position_ = _transform;
}

void Sword::AttackSword()
{
    if(flag_)
    {
        BoxCollider* collision = new BoxCollider(XMFLOAT3(transform_.position_.x, 0, transform_.position_.z), XMFLOAT3(1, 1, 1));
        AddCollider(collision);
    }

    while(transform_.rotate_.x <= 120.0f)
    {
        transform_.rotate_.x += 10.0f;
    }
}

void Sword::AttackBeside()
{
    attackflag_ = false;

    while (transform_.rotate_.z <= 100)
    {
        transform_.rotate_.z += 0.5f;
    }

    while (transform_.rotate_.z >= -100)
    {
        transform_.rotate_.z -= 0.5f;
    }
 
    attackflag_ = true;
}
