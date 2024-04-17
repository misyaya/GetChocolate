#include "Title_Image.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Title_Image::Title_Image(GameObject* parent)
	:GameObject(parent, "Title_Image"),
	hBack_(-1), hLogo_(-1), hKey_(-1), 
	keyAlpha_(0), keyShading_(0)
{
}

//�f�X�g���N�^
Title_Image::~Title_Image()
{
}

//������
void Title_Image::Initialize()
{
	//�摜�f�[�^�̃��[�h
	//�w�i
	hBack_ = Image::Load("Image/backGround.png");
	assert(hBack_ >= 0);

	//�^�C�g�����S
	hLogo_ = Image::Load("Image/title_Logo.png");
	assert(hLogo_ >= 0);

	//�L�[����U��
	hKey_ = Image::Load("Image/pressSpace.png");
	assert(hKey_ >= 0);



	//�摜���
	//���S
	trLogo_.position_.y += 0.5f;  //y���W

	//�L�[����U��
	trKey_.scale_ = XMFLOAT3(0.5f, 0.5f, 0.5f);   //�g�嗦
	trKey_.position_.y -= 0.5f;                   //y���W
}

//�X�V
void Title_Image::Update()
{
	//�X�y�[�X�L�[�������ꂽ��Q�[����ʂɈڍs
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MAINGAME);
	}



	//�L�[����U���̓_��
	if (keyAlpha_ >= 200)  //�����x��200�ȏ�ɂȂ�Ή�����
	{
		keyShading_ = -5;
	}
	else if (keyAlpha_ <= 0) //�����x��0�ȉ��ɂȂ�Ώグ��
	{
		keyShading_ = 5;
	}

	//hKey_�����x�̌v�Z
	keyAlpha_ += keyShading_;

	//hKey_�����x���Z�b�g
	Image::SetAlpha(hKey_, keyAlpha_);
}

//�`��
void Title_Image::Draw()
{
	//�w�i
	Image::SetTransform(hBack_, trBack_);
	Image::Draw(hBack_);

	//�^�C�g�����S
	Image::SetTransform(hLogo_, trLogo_);
	Image::Draw(hLogo_);

	//�L�[����U��
	Image::SetTransform(hKey_, trKey_);
	Image::Draw(hKey_);
}

//�J��
void Title_Image::Release()
{
}