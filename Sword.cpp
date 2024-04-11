#include "Sword.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Audio.h"

//コンストラクタ
Sword::Sword(GameObject* parent)
    :GameObject(parent, "Sword"), sword_(-1),sSword_(-1)
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
    sword_ = Model::Load("Fbx/Sword.fbx");
    assert(sword_ >= 0);

    //サウンドデータのロード
    //剣(振り下ろす)
    sSword_ = Audio::Load("Sound/sword.WAV");
    assert(sSword_ >= 0);

    transform_.position_.y = 2.0f;
    transform_.position_.z = 5.0f;
    transform_.position_.x = 20.0f;

    state_ = ATTACK;
}

//更新
void Sword::Update()
{  
	XMFLOAT3 fMove = XMFLOAT3(0, 0, 0);


	//前
	if (Input::IsKey(DIK_W))
	{
		fMove.z = 0.1f;
	}

	//後
	if (Input::IsKey(DIK_S))
	{
		fMove.z = -0.1f;
	}

	//左
	if (Input::IsKey(DIK_A))
	{
		fMove.x = -0.1f;
	}

	//右
	if (Input::IsKey(DIK_D))
	{
		fMove.x = 0.1f;
	}

	//一定の速度で動く方法
	XMVECTOR vMove;
	vMove = XMLoadFloat3(&fMove);
	vMove = XMVector3Normalize(vMove);

	//速度　半径未満にしないとめり込む
	vMove *= 0.09f;
	XMStoreFloat3(&fMove, vMove);

	transform_.position_.x += fMove.x;
	transform_.position_.z += fMove.z;

	//向き変更
	XMVECTOR vLength = XMVector3Length(vMove); //ベクトルの長さ
	float length = XMVectorGetX(vLength);
	if (length != 0)
	{
		//プレイヤーのデフォルトの前方向↑（奥向いてる）
		XMVECTOR vFront = { 0,0,1,0 };
		//vMpve正規化
		vMove = XMVector3Normalize(vMove);

		//内積Ａ・Ｂ
		//      ↑dot
		XMVECTOR vDot = XMVector3Dot(vFront, vMove);
		float dot = XMVectorGetX(vDot);
		float angle = acos(dot);


		//左右判断         ↓外積を求める
		XMVECTOR vCross = XMVector3Cross(vFront, vMove);
		if (XMVectorGetY(vCross) < 0)
		{
			angle *= -1;
		}

		//XMConvertToDegrees ラジアンを度に変換する　　Radians
		transform_.rotate_.y = XMConvertToDegrees(angle);
	}


    //スペースキーが押されていたら
    if (Input::IsKeyDown(DIK_SPACE))
    {
        AttackSword();  
    }

    if (colliderFlag_ == true)
    {
        ClearCollider();
        colliderFlag_ = false;
    }
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
        colliderFlag_ = true; 
        attackFlag_ = false;
        FinishAttack();
    }
}

void Sword::SetSwordTr(XMFLOAT3 _transform)
{
    transform_.position_ = _transform;
}

void Sword::AttackSword()
{
    if(attackFlag_ == false)
    {
        BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1));
        AddCollider(collision);

        Audio::Play(sSword_);

        while (transform_.rotate_.x <= 120.0f)
        {
            transform_.rotate_.x += 10.0f;
        }
    }

    attackFlag_ = true;
 
}


void Sword::FinishAttack()
{
    transform_.rotate_.x = 0;
}

void Sword::SetSwordPos(XMFLOAT3 _position)
{
    transform_.position_ = _position;
}

XMFLOAT3 Sword::GetSwordPos()
{
    return transform_.position_;
}

void Sword::MoveBackward(float _distance)
{
    // プレイヤーの現在位置を取得
    XMFLOAT3 currentPosition = GetSwordPos();

    // プレイヤーを後ろに移動
    currentPosition.z += _distance;

    // 移動後の位置を設定
    SetSwordPos(currentPosition);
}
