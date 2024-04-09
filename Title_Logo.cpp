#include "Title_Logo.h"
#include "Engine/Image.h"

//�R���X�g���N�^
Title_Logo::Title_Logo(GameObject* parent)
    :GameObject(parent, "Title_Logo"), hLogo_(-1)
{
}

//�f�X�g���N�^
Title_Logo::~Title_Logo()
{
}

//������
void Title_Logo::Initialize()
{
	//�摜�f�[�^�̃��[�h
	//�^�C�g�����S
	hLogo_ = Image::Load("Image/title_Logo.png");
	assert(hLogo_ >= 0);

	logoTr_.position_.y += 0.5f;
}

//�X�V
void Title_Logo::Update()
{
}

//�`��
void Title_Logo::Draw()
{
	//�^�C�g�����S
	Image::SetTransform(hLogo_, logoTr_);
	Image::Draw(hLogo_);
}

//�J��
void Title_Logo::Release()
{
}