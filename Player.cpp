#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Engine/BoxCollider.h"
#include "Engine/Image.h"
#include <chrono>

using namespace std::chrono;
//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1),nowHp_(3),maxHp_(3), hPictHp_(-1), hB_(-1),pText(nullptr)
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
	/*hPictHp_ = Image::Load("HpFive.png");
	assert(hPictHp_ >= 0);*/

	hB_ = Image::Load("brick.jpg");
	assert(hB_ >= 0);
	
	Instantiate<Sword>(this);

	
	hpTr_.position_ = XMFLOAT3(-0.6f, 0.8f, 0.0f);
	
	kari.scale_ = XMFLOAT3(0.5f,0.3f,0.5f);
	

	BoxCollider* collision2 = new BoxCollider(XMFLOAT3(0, 2.0f, 0), XMFLOAT3(1.0f, 3.0f, 0.5f));
	AddCollider(collision2);

	pText = new Text;

	pText->Initialize();
}

//更新
void Player::Update()
{


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
		//sword->SetSowrdTr(XMFLOAT3(0.5f, 0.0f, 0.0f));
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

	/*LifeGauge* pGauge = (LifeGauge*)FindObject("LifeGauge");
	pGauge->SetHp(nowHp_, maxHp_);*/
}

//描画
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

	/*Image::SetRect(hPictHp_, 512, 64, 60, 64);
	Image::SetTransform(hPictHp_, hpTr_);
	Image::Draw(hPictHp_);*/

	//Image::SetRect(hB_, 0, 0, 2048, 1000);
	//Image::SetTransform(hB_, kari);
	//Image::Draw(hB_);

	pText->Draw(30, 30, nowHp_);
}

//開放
void Player::Release()
{
}

//当たり判定
void Player::OnCollision(GameObject* pTarget)
{
	switch (situation)
	{
	case WAIT:
		break;

	case DAMAGE:
		//敵に当たったとき
		if (pTarget->GetObjectName() == "Enemy")
		{
			nowHp_--;
			situation = WAIT;
			std::chrono::steady_clock::now();
		}

		break;

	}
	
}

void Player::SetInvulnerable()
{
}

void Player::SetPlayrPos(XMFLOAT3 _position)
{

}

