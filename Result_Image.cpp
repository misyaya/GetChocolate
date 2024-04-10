#include "Result_Image.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
Result_Image::Result_Image(GameObject* parent)
	:GameObject(parent, "Result_Image"),
	hBack_(-1), hBackLittle_(-1), hResultName_(-1), hKey_(-1), 
	keyAlpha_(0), keyShading_(0)
{
}

//�f�X�g���N�^
Result_Image::~Result_Image()
{
}

//������
void Result_Image::Initialize()
{
	//�摜�f�[�^�̃��[�h
	//�w�i
	hBack_ = Image::Load("Image/BackGround.png");
	assert(hBack_ >= 0);

	//�w�i��
	hBackLittle_ = Image::Load("Image/result_BackLittle.png");
	assert(hBackLittle_ >= 0);

	//Result����
	hResultName_ = Image::Load("Image/resultName.png");
	assert(hResultName_ >= 0);

	//�L�[����U��
	hKey_ = Image::Load("Image/pressSpace.png");
	assert(hKey_ >= 0);



	//�摜���
	//�w�i(��)
	trBackL_.position_.y = -0.4f;                  //y���W
	trBackL_.scale_ = XMFLOAT3(0.9f, 0.2f, 1.0f);  //�g�嗦

	//Result����
	trResultN_.position_.y = 0.8f;                   //y���W
	trResultN_.scale_ = XMFLOAT3(0.4f, 0.4f, 1.0f);  //�g�嗦

	//�L�[����U��
	trKey_.scale_ = XMFLOAT3(0.5f, 0.5f, 0.5f);   //�g�嗦
	trKey_.position_.y -= 0.5f;                   //y���W
}

//�X�V
void Result_Image::Update()
{
	//�X�y�[�X�L�[�������ꂽ��Q�[����ʂɈڍs
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
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

	//�����x�̌v�Z
	keyAlpha_ += keyShading_;

	//�����x���Z�b�g
	Image::SetAlpha(hKey_, keyAlpha_);
}

//�`��
void Result_Image::Draw()
{
	//�w�i
	Image::SetAlpha(hBack_, 128);
	Image::SetTransform(hBack_, trBack_);
	Image::Draw(hBack_);

	//�w�i(��)
	Image::SetAlpha(hBackLittle_, 100);
	Image::SetTransform(hBackLittle_, trBackL_);
	Image::Draw(hBackLittle_);

	//Result����
	Image::SetTransform(hResultName_, trResultN_);
	Image::Draw(hResultName_);

	//�L�[����U��
	Image::SetTransform(hKey_, trKey_);
	Image::Draw(hKey_);
}

//�J��
void Result_Image::Release()
{
}