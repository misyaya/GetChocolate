#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"
#include "Engine/BoxCollider.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Audio.h"
#include "Enemy.h"
#include "Sword.h"
#include "ValueManager.h"
#include <chrono>



using namespace std::chrono;
int enemyKill = 0;

//コンストラクタ
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1), nowHp_(3), maxHp_(3), hPictHp_(-1), hB_(-1),
	pText(nullptr), pTextHp(nullptr), pTextC(nullptr), pChoco(nullptr), pTextE(nullptr), pEnemy(nullptr),
	invinTime(0.0f),invinState(InvincibilityState::Normal), deltaTime(3.0f),
	sWalk_(-1), sDamage_(-1), sInvin_(-1), sChocoGet_(-1), chocoPoint_(0), enemyPoint_(0)
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
	hModel_ = Model::Load("Fbx/Player.fbx");
	assert(hModel_ >= 0);

	//サウンドデータのロード
	//足音
	sWalk_ = Audio::Load("Sound/walk.WAV"); 	
	assert(sWalk_ >= 0);
	
	//ダメージ音
	sDamage_ = Audio::Load("Sound/damage.WAV"); 	
	assert(sDamage_ >= 0);

	//無敵時間中の接敵
	sInvin_ = Audio::Load("Sound/invincible.WAV"); 	
	assert(sInvin_ >= 0);

	//チョコレートを入手
	sChocoGet_ = Audio::Load("Sound/chocoGet.WAV"); 	
	assert(sChocoGet_ >= 0);
	
	hpTr_.position_ = XMFLOAT3(-0.6f, 0.8f, 0.0f);
	
	tentative.scale_ = XMFLOAT3(0.5f,0.3f,0.5f);


	BoxCollider* collision2 = new BoxCollider(XMFLOAT3(0, 2.0f, 0), XMFLOAT3(1.0f, 3.0f, 0.5f));
	AddCollider(collision2);

	pText = new Text;
	pText->Initialize();

	pTextHp = new Text;
	pTextHp->Initialize();

	pTextC = new Text;
	pTextC->Initialize();

	pChoco = new Text;
	pChoco->Initialize();
	
	pTextE = new Text;
	pTextE->Initialize();

	pEnemy = new Text;
	pEnemy->Initialize();


	transform_.position_ = XMFLOAT3(20.0f, 0.0f, 1.0f);


	//武器の呼び出し
	//Instantiate<Sword>(this);


	//ステージの位置
	pFloor_ = (Floor*)FindObject("Floor");

}

//更新
void Player::Update()
{
	XMFLOAT3 fMove = XMFLOAT3(0, 0, 0);

	SetInvulnerable();
	
	//前
	if (Input::IsKey(DIK_W))
	{
		fMove.z = 0.1f;
		Audio::Play(sWalk_);
	}

	//後
	if (Input::IsKey(DIK_S))
	{
		fMove.z = -0.1f;
		Audio::Play(sWalk_);
	}

	//左
	if (Input::IsKey(DIK_A))
	{
		fMove.x = -0.1f;
		Audio::Play(sWalk_);
	}

	//右
	if (Input::IsKey(DIK_D))
	{
		fMove.x = 0.1f;
		Audio::Play(sWalk_);
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

	//壁との当たり判定
	int checkX1, checkX2;
	int checkZ1, checkZ2;


	//右
	{
		checkX1 = (int)(transform_.position_.x + 0.3f);
		checkZ1 = (int)(transform_.position_.z + 0.2f);
		checkX2 = (int)(transform_.position_.x + 0.3f);
		checkZ2 = (int)(transform_.position_.z - 0.2f);
		if (pFloor_->IsWall(checkX1, checkZ1) == true ||
			pFloor_->IsWall(checkX2, checkZ2) == true)
		{
			transform_.position_.x = (float)((int)transform_.position_.x) + 1.0f - 0.3f;
		}
	}

	//左
	{
		checkX1 = (int)(transform_.position_.x - 0.3f);
		checkZ1 = (int)(transform_.position_.z + 0.2f);
		checkX2 = (int)(transform_.position_.x - 0.3f);
		checkZ2 = (int)(transform_.position_.z - 0.2f);
		if (pFloor_->IsWall(checkX1, checkZ1) == true ||
			pFloor_->IsWall(checkX2, checkZ2) == true)
		{
			transform_.position_.x = (float)((int)transform_.position_.x) + 0.3f;
		}
	}

	//手前
	{
		checkX1 = (int)(transform_.position_.x + 0.2f);
		checkZ1 = (int)(transform_.position_.z - 0.3f);
		checkX2 = (int)(transform_.position_.x - 0.2f);
		checkZ2 = (int)(transform_.position_.z - 0.3f);
		if (pFloor_->IsWall(checkX1, checkZ1) == true ||
			pFloor_->IsWall(checkX2, checkZ2) == true)
		{
			transform_.position_.z = (float)((int)transform_.position_.z) + 0.3f;
		}
	}

	//奥
	{
		checkX1 = (int)(transform_.position_.x + 0.2f);
		checkZ1 = (int)(transform_.position_.z + 0.3f);
		checkX2 = (int)(transform_.position_.x - 0.2f);
		checkZ2 = (int)(transform_.position_.z + 0.3f);
		if (pFloor_->IsWall(checkX1, checkZ1) == true ||
			pFloor_->IsWall(checkX2, checkZ2) == true)
		{
			transform_.position_.z = (float)((int)transform_.position_.z) + 1.0f - 0.3f;
		}
	}


	static float velocity_;

	if (Input::IsKey(DIK_RETURN))
	{
		velocity_ = 0.15f;
	}
	if (velocity_ != 0.0f)
	{
		velocity_ -= 0.02f;

		transform_.position_.y += velocity_;
	}
	
	if(transform_.position_.y <= 0.0f )
	{
		transform_.position_.y = 0.0f;
	}


	chocoPoint_ = ValueManager::GetInstance().GetPoints();
	enemyPoint_ = ValueManager::GetInstance().GetEnemyD();

	//カメラ
	UpdateCamera();

	Enemy* enemy = static_cast<Enemy*>(FindObject("Enemy"));
	if (enemy)
	{
		enemy->SetPlayer(this);
	}

	if (nowHp_ <= 0  || chocoPoint_ >= 5)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_RESULT);
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

	//チョコレート獲得数
	pTextC->Draw(30, 60, "CH");
	pChoco->Draw(90, 60, chocoPoint_);

	//エネミー撃破数
	pTextE->Draw(30, 90, "EN");
	pEnemy->Draw(90, 90, enemyPoint_);
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
		// 既に無敵状態の場合は何もしない
		if (invinState == InvincibilityState::Invincible)
		{
			Audio::Play(sInvin_);
			return;
		}
		else
		{
			Audio::Play(sDamage_);
			nowHp_--;
			invinTime = invinDuration;
			invinState = InvincibilityState::Invincible;

			float knockbackDistance = -10.0f; //後ろに飛ぶ距離
			MoveBackward(knockbackDistance);
		}
	}

	//チョコレートに当たったとき
	if (pTarget->GetObjectName() == "Chocolate")
	{
		Audio::Play(sChocoGet_);
	}

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
	XMFLOAT3 newPosition = XMFLOAT3(playerPosition.x, playerPosition.y + 6, playerPosition.z - 5);

	// カメラの焦点
	XMFLOAT3 newTarget = XMFLOAT3(playerPosition.x, playerPosition.y + 1 , playerPosition.z + 10);

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

