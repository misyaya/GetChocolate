#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Sample.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void Player::Update()
{
	

	if (Input::IsKey(DIK_W))
	{
		kari.position_.z += 0.1f;
		kari.rotate_.y = front.rotate_.y;
	}

	if (Input::IsKey(DIK_S))
	{
		kari.position_.z -= 0.1f;
		kari.rotate_.y = front.rotate_.y;
	}


	if (Input::IsKey(DIK_D))
	{
		kari.position_.x += 0.1f;
		kari.rotate_.y = front.rotate_.y + 90.0f;
	}

	if (Input::IsKey(DIK_A))
	{
		kari.position_.x -= 0.1f;
		kari.rotate_.y = front.rotate_.y - 90.0f;
	}

	Camera::SetPosition(XMFLOAT3(kari.position_.x, 4, kari.position_.z - 8));
	Camera::SetTarget(XMFLOAT3(kari.position_.x, 4, 0));

	
}

//�`��
void Player::Draw()
{
	Model::SetTransform(hModel_, kari);
	Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}