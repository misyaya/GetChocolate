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
//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1),nowHp_(3),maxHp_(3), hPictHp_(-1), hB_(-1),pText(nullptr),pTextHp(nullptr),
	invinTime(0.0f),invinState(InvincibilityState::Normal),deltaTime(3.0f)
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

//�X�V
void Player::Update()
{
	SetInvulnerable();
	
	//�O
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.z += 0.1f;
		transform_.rotate_.y = front.rotate_.y;
	}

	//��
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.z -= 0.1f;
		//transform_.rotate_.y = front.rotate_.y - 180.0f;
	}

	//��
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.1f;
		//transform_.rotate_.y = front.rotate_.y + 90.0f;
	}

	//�E
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.1f;
		//transform_.rotate_.y = front.rotate_.y - 90.0f;
	}

	


	//�J����
	UpdateCamera();

	Enemy* enemy = static_cast<Enemy*>(FindObject("Enemy"));
	if (enemy)
	{
		enemy->SetPlayer(this);
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
}

//�J��
void Player::Release()
{
}

//�����蔻��
void Player::OnCollision(GameObject* pTarget)
{
	//�G�ɓ��������炿����ƌ��ɔ�Ԃ悤�ɂ�����
	//�G�ɓ��������Ƃ�
	if (pTarget->GetObjectName() == "Enemy")
	{	
		// ���ɖ��G��Ԃ̏ꍇ�͉������Ȃ�
		if (invinState == InvincibilityState::Invincible)
		{
			return;
		}
		else
		{
			nowHp_--;
			invinTime = invinDuration;
			invinState = InvincibilityState::Invincible;

			//float knockbackDistance = -10.0f; //���ɔ�ԋ���
			//MoveBackward(knockbackDistance);

			if (nowHp_ <= 0)
			{
				SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
				pSceneManager->ChangeScene(SCENE_ID_RESULT);
			}
		}
	}

	//�`���R�ɓ��������Ƃ�
	/*if (pTarget->GetObjectName() == "Chocolate")
	{
		
	}*/

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
	XMFLOAT3 newPosition = XMFLOAT3(playerPosition.x, playerPosition.y + 5, playerPosition.z - 8);

	// �J�����̏œ_
	XMFLOAT3 newTarget = XMFLOAT3(playerPosition.x, playerPosition.y + 2, playerPosition.z + 5);

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

