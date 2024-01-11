#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Engine/BoxCollider.h"
#include "Sword.h"
#include "Engine/Image.h"

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1),nowHp_(3),hPictHp_(-1)
{
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

	//画像データのロード
	hPictHp_ = Image::Load("HpFive.png");
	assert(hPictHp_ >= 0);
	
	Instantiate<Sword>(this);

	
	hpTr_.position_ = XMFLOAT3(-0.6f, 0.8f, 0.0f);
	
	

	BoxCollider* collision2 = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1.0f, 7.0f, 0.5f));
	AddCollider(collision2);

	
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

	Image::SetRect(hPictHp_, 0, 0, 10, 10);
	Image::SetTransform(hPictHp_, hpTr_);
	Image::Draw(hPictHp_);
	
}

//開放
void Player::Release()
{
}

//当たり判定
void Player::OnCollision(GameObject* pTarget)
{
	//敵に当たったとき
	if (pTarget->GetObjectName() == "Enemy")
	{
		nowHp_--;
	}
}

void Player::SetPlayrPos(XMFLOAT3 _position)
{

}

