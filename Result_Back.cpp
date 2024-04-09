#include "Result_Back.h"
#include "Engine/Image.h"
#include "Engine/Image.h"

//�R���X�g���N�^
Result_Back::Result_Back(GameObject* parent)
	:GameObject(parent, "Result_Back"), hBack_(-1)
{
}

//�f�X�g���N�^
Result_Back::~Result_Back()
{
}

//������
void Result_Back::Initialize()
{
	//�摜�f�[�^�̃��[�h
	//�w�i
	hBack_ = Image::Load("Image/BackGround.png");
	assert(hBack_ >= 0);
}

//�X�V
void Result_Back::Update()
{
}

//�`��
void Result_Back::Draw()
{
	//�w�i
	Image::SetAlpha(hBack_, 128);
	Image::SetTransform(hBack_, backTr_);
	Image::Draw(hBack_);
}

//�J��
void Result_Back::Release()
{
}