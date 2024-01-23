#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Engine/BoxCollider.h"
#include "Engine/Image.h"
#include <chrono>
#include "Enemy.h"

using namespace std::chrono;
//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1),nowHp_(3),maxHp_(3), hPictHp_(-1), hB_(-1),pText(nullptr),
	invinTime(0.0f),invinState(InvincibilityState::Normal),deltaTime(3.0f)
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
	if (invinState == InvincibilityState::Invincible)
	{
		invinTime -= deltaTime;

		if (invinTime <= 0.0f)
		{
			invinState = InvincibilityState::Normal;
		}
	}
	
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

	Enemy* enemy = static_cast<Enemy*>(FindObject("Enemy"));
	if (enemy)
	{
		enemy->SetPlayer(this);
	}
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
	//敵に当たったらちょっと後ろに飛ぶようにしたい
	//敵に当たったとき
	if (pTarget->GetObjectName() == "Enemy")
	{	
		// 既に無敵状態の場合は何もしない
		if (invinState == InvincibilityState::Invincible)
		{
			return;
		}
		else
		{
			nowHp_--;
			invinTime = invinDuration;
			invinState = InvincibilityState::Invincible;

			if (nowHp_ <= 0)
			{

			}
		}
	}

}

void Player::SetInvulnerable()
{
}

void Player::SetPlayerPos(XMFLOAT3 _position)
{

}

