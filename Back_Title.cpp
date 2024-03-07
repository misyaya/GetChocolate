#include "Back_Title.h"
#include "Engine/Image.h"
#include "Engine/Image.h"

//�R���X�g���N�^
Back_Title::Back_Title(GameObject* parent)
    :GameObject(parent, "Back_Title"), hBack_(-1)
{
}

//�f�X�g���N�^
Back_Title::~Back_Title()
{
}

//������
void Back_Title::Initialize()
{
	//�摜�f�[�^�̃��[�h
	//�w�i
	hBack_ = Image::Load("TitleBack.png");
	assert(hBack_ >= 0);
}

//�X�V
void Back_Title::Update()
{
}

//�`��
void Back_Title::Draw()
{
	//�w�i
	Image::SetTransform(hBack_, backTr_);
	Image::Draw(hBack_);
}

//�J��
void Back_Title::Release()
{
}