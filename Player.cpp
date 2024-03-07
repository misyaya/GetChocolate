#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Engine/BoxCollider.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Enemy.h"
#include <chrono>



using namespace std::chrono;
//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1),nowHp_(3),maxHp_(3), hPictHp_(-1), hB_(-1),pText(nullptr),pTextHp(nullptr),
	invinTime(0.0f),invinState(InvincibilityState::Normal),deltaTime(3.0f)
{
	Camera::SetPosition(XMFLOAT3(tentative.position_.x, 4, tentative.position_.z - 8));
	Camera::SetTarget(XMFLOAT3(tentative.position_.x, 4, 0));
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);
	
	
	hpTr_.position_ = XMFLOAT3(-0.6f, 0.8f, 0.0f);
	
	tentative.scale_ = XMFLOAT3(0.5f,0.3f,0.5f);
	//Instantiate<Sword>(this);

	BoxCollider* collision2 = new BoxCollider(XMFLOAT3(0, 2.0f, 0), XMFLOAT3(1.0f, 3.0f, 0.5f));
	AddCollider(collision2);

	pText = new Text;
	pText->Initialize();

	pTextHp = new Text;
	pTextHp->Initialize();
	

	transform_.position_ = XMFLOAT3(0.0f,0.0f,-1.0f);
}

//更新
void Player::Update()
{
	SetInvulnerable();
	
	//前
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.z += 0.1f;
		transform_.rotate_.y = front.rotate_.y;
	}

	//後
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.z -= 0.1f;
		//transform_.rotate_.y = front.rotate_.y - 180.0f;
	}

	//左
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.1f;
		//transform_.rotate_.y = front.rotate_.y + 90.0f;
	}

	//右
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.1f;
		//transform_.rotate_.y = front.rotate_.y - 90.0f;
	}

	


	//カメラ
	UpdateCamera();

	Enemy* enemy = static_cast<Enemy*>(FindObject("Enemy"));
	if (enemy)
	{
		enemy->SetPlayer(this);
	}

}

//描画
void Player::Draw()
{
	//プレイヤー
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

	//HP　数字
	pText->Draw(30, 30, "HP");
	pTextHp->Draw(90, 30, nowHp_);
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

			//float knockbackDistance = -10.0f; //後ろに飛ぶ距離
			//MoveBackward(knockbackDistance);

			if (nowHp_ <= 0)
			{
				SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
				pSceneManager->ChangeScene(SCENE_ID_RESULT);
			}
		}
	}

	//チョコに当たったとき
	/*if (pTarget->GetObjectName() == "Chocolate")
	{
		
	}*/

}

void Player::SetInvulnerable()
{
	//無敵時間か否か　残り時間
	if (invinState == InvincibilityState::Invincible)
	{
		invinTime -= deltaTime;

		if (invinTime <= 0.0f)
		{
			invinState = InvincibilityState::Normal;
		}
	}
}

void Player::SetPlayerPos(XMFLOAT3 _position)
{
	transform_.position_ = _position;
}

XMFLOAT3 Player::GetPlayerPos()
{
	return transform_.position_;
}

void Player::UpdateCamera()
{
	// プレイヤーの位置
	XMFLOAT3 playerPosition = GetPlayerPos();

	// カメラの位置
	XMFLOAT3 newPosition = XMFLOAT3(playerPosition.x, playerPosition.y + 5, playerPosition.z - 8);

	// カメラの焦点
	XMFLOAT3 newTarget = XMFLOAT3(playerPosition.x, playerPosition.y + 2, playerPosition.z + 5);

	// カメラの位置と焦点を設定
	Camera::SetPosition(newPosition);
	Camera::SetTarget(newTarget);

	// カメラ更新
	Camera::Update();
}

void Player::MoveBackward(float _distance)
{
	// プレイヤーの現在位置を取得
	XMFLOAT3 currentPosition = GetPlayerPos();

	// プレイヤーを後ろに移動
	currentPosition.z += _distance;

	// 移動後の位置を設定
	SetPlayerPos(currentPosition);

}

