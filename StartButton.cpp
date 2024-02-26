#include "StartButton.h"
#include "Engine/Image.h"

//�R���X�g���N�^
StartButton::StartButton(GameObject* parent)
    :GameObject(parent, "StartButton"), hButton_(-1)
{
}

//�f�X�g���N�^
StartButton::~StartButton()
{
}

//������
void StartButton::Initialize()
{
	//�{�^��
	hButton_ = Image::Load("TitleButton.png");
	assert(hButton_ >= 0);

	buttonTr_.scale_ = XMFLOAT3(0.5f, 0.5f, 0.5f);
	buttonTr_.position_.y -= 0.5f;
}

//�X�V
void StartButton::Update()
{
}

//�`��
void StartButton::Draw()
{
	//�{�^��
	Image::SetTransform(hButton_, buttonTr_);
	Image::Draw(hButton_);
}

//�J��
void StartButton::Release()
{
}