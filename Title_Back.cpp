#include "Title_Back.h"
#include "Engine/Image.h"
#include "Engine/Image.h"

//�R���X�g���N�^
Title_Back::Title_Back(GameObject* parent)
    :GameObject(parent, "Title_Back"), hBack_(-1)
{
}

//�f�X�g���N�^
Title_Back::~Title_Back()
{
}

//������
void Title_Back::Initialize()
{
	//�摜�f�[�^�̃��[�h
	//�w�i
	hBack_ = Image::Load("Image/BackGround.png");
	assert(hBack_ >= 0);
}

//�X�V
void Title_Back::Update()
{
}

//�`��
void Title_Back::Draw()
{
	//�w�i
	Image::SetTransform(hBack_, backTr_);
	Image::Draw(hBack_);
}

//�J��
void Title_Back::Release()
{
}