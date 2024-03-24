#include "TitleLogo.h"
#include "Engine/Image.h"

//�R���X�g���N�^
TitleLogo::TitleLogo(GameObject* parent)
    :GameObject(parent, "TitleLogo"), hLogo_(-1)
{
}

//�f�X�g���N�^
TitleLogo::~TitleLogo()
{
}

//������
void TitleLogo::Initialize()
{
	//�摜�f�[�^�̃��[�h
	//�^�C�g�����S
	hLogo_ = Image::Load("titleLogo.png");
	assert(hLogo_ >= 0);

	logoTr_.position_.y += 0.5f;
}

//�X�V
void TitleLogo::Update()
{
}

//�`��
void TitleLogo::Draw()
{
	//�^�C�g�����S
	Image::SetTransform(hLogo_, logoTr_);
	Image::Draw(hLogo_);
}

//�J��
void TitleLogo::Release()
{
}