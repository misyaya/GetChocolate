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
#include <chrono>
#include "ValueManager.h"



using namespace std::chrono;
int enemyKill = 0;

//�R���X�g���N�^
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1), nowHp_(3), maxHp_(3), hPictHp_(-1), hB_(-1),
	pText(nullptr), pTextHp(nullptr), pTextC(nullptr), pChoco(nullptr), pTextE(nullptr), pEnemy(nullptr),
	invinTime(0.0f),invinState(InvincibilityState::Normal), deltaTime(3.0f),
	sWalk_(-1), sDamage_(-1), sInvin_(-1), sChocoGet_(-1), chocoPoint_(0), enemyPoint_(0)
{
	Camera::SetPosition(XMFLOAT3(tentative.position_.x, 4, tentative.position_.z - 8));
	Camera::SetTarget(XMFLOAT3(tentative.position_.x, 4, 0));
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Fbx/Player.fbx");
	assert(hModel_ >= 0);

	//�T�E���h�f�[�^�̃��[�h
	sWalk_ = Audio::Load("Sound/walk.WAV"); 	//����
	assert(sWalk_ >= 0);
	
	sDamage_ = Audio::Load("Sound/damage.WAV"); 	//�_���[�W��
	assert(sDamage_ >= 0);

	sInvin_ = Audio::Load("Sound/invincible.WAV"); 	//���G���Ԓ��̐ړG
	assert(sInvin_ >= 0);

	sChocoGet_ = Audio::Load("Sound/chocoGet.WAV"); 	//�`���R���[�g�����
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

	Instantiate<Sword>(this);

}

//�X�V
void Player::Update()
{
	SetInvulnerable();
	
	//�O
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.z += 0.1f;
		transform_.rotate_.y = front.rotate_.y;
		Audio::Play(sWalk_);
	}

	//��
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.z -= 0.1f;
		Audio::Play(sWalk_);
	}

	//��
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.1f;
		Audio::Play(sWalk_);
	}

	//�E
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.1f;
		Audio::Play(sWalk_);
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

	//�J����
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

//�`��
void Player::Draw()
{
	
	//�v���C���[
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

	//HP�@����
	pText->Draw(30, 30, "HP");
	pTextHp->Draw(90, 30, nowHp_);

	//�`���R���[�g�l����
	pTextC->Draw(30, 60, "CH");
	pChoco->Draw(90, 60, chocoPoint_);

	//�G�l�~�[���j��
	pTextE->Draw(30, 90, "EN");
	pEnemy->Draw(90, 90, enemyPoint_);
}

//�J��
void Player::Release()
{
}

//�����蔻��
void Player::OnCollision(GameObject* pTarget)
{
	//�G�ɓ��������Ƃ�
	if (pTarget->GetObjectName() == "Enemy")
	{	
		// ���ɖ��G��Ԃ̏ꍇ�͉������Ȃ�
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

			float knockbackDistance = -10.0f; //���ɔ�ԋ���
			MoveBackward(knockbackDistance);

		}
	}

	//�`���R���[�g�ɓ��������Ƃ�
	if (pTarget->GetObjectName() == "Chocolate")
	{
		Audio::Play(sChocoGet_);
	}

}

void Player::SetInvulnerable()
{
	//���G���Ԃ��ۂ��@�c�莞��
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
	// �v���C���[�̈ʒu
	XMFLOAT3 playerPosition = GetPlayerPos();

	// �J�����̈ʒu
	XMFLOAT3 newPosition = XMFLOAT3(playerPosition.x, playerPosition.y + 6, playerPosition.z - 5);

	// �J�����̏œ_
	XMFLOAT3 newTarget = XMFLOAT3(playerPosition.x, playerPosition.y + 1 , playerPosition.z + 10);

	// �J�����̈ʒu�Əœ_��ݒ�
	Camera::SetPosition(newPosition);
	Camera::SetTarget(newTarget);

	// �J�����X�V
	Camera::Update();
}

void Player::MoveBackward(float _distance)
{
	// �v���C���[�̌��݈ʒu���擾
	XMFLOAT3 currentPosition = GetPlayerPos();

	// �v���C���[�����Ɉړ�
	currentPosition.z += _distance;

	// �ړ���̈ʒu��ݒ�
	SetPlayerPos(currentPosition);

}

