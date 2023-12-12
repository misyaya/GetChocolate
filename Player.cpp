#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Engine/BoxCollider.h"
#include "Sword.h"

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1),nowHp_(180)
{
	transform_.position_ = XMFLOAT3(0.0, 0.0, 0.0);
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Sample.fbx");
	assert(hModel_ >= 0);

	
	Instantiate<Sword>(this);

	//SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 1.0, 0), 1.2f);
	//AddCollider(collision);

	BoxCollider* collision2 = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1.0f, 7.0f, 0.5f));
	AddCollider(collision2);

	

	//LifeGauge gauge();
}

//更新
void Player::Update()
{
	kari = transform_;


	if (Input::IsKey(DIK_W))
	{
		transform_.position_.z += 0.1f;
		transform_.rotate_.y = front.rotate_.y;
	}

	if (Input::IsKey(DIK_S))
	{
		transform_.position_.z -= 0.1f;
		transform_.rotate_.y = front.rotate_.y;
	}
	

	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.1f;
		transform_.rotate_.y = front.rotate_.y + 90.0f;
	}

	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.1f;
		transform_.rotate_.y = front.rotate_.y - 90.0f;
	}

	Camera::SetPosition(XMFLOAT3(kari.position_.x, 4, kari.position_.z - 8));
	Camera::SetTarget(XMFLOAT3(kari.position_.x, 4, 0));
}

//描画
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}

//当たり判定
void Player::OnCollision(GameObject* pTarget)
{
	//LifeGauge* pLifeGauge = (LifeGauge*)FindObject("LifeGauge");

	//敵に当たったとき
	if (pTarget->GetObjectName() == "Enemy")
	{
		//pLifeGauge->AddValue(-1);

	}
}

XMFLOAT3 Player::GetPlayerTr()
{
	return transform_.position_;
}

