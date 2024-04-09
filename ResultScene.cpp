#include "ResultScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Image.h"
#include "ValueManager.h"
#include "Result_Instruction.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Result_Back.h"
#include "Result_Text.h"

//�R���X�g���N�^
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"),
	hBackSmall_(-1), hResultName_(-1), hPerfect_(-1), hGameClear_(-1)
{
}

//������
void ResultScene::Initialize()
{
	Instantiate<Result_Back>(this);

	//�摜�f�[�^�̃��[�h
	//�w�i��
	hBackSmall_ = Image::Load("Image/result_BackLittle.png");
	assert(hBackSmall_ >= 0);

	//Result����
	hResultName_ = Image::Load("Image/resultName.png");
	assert(hResultName_ >= 0);

	//Perfect����
	hPerfect_ = Image::Load("Image/perfect.png");
	assert(hPerfect_ >= 0);


	transform_.position_.x = transform_.position_.x + 0.1f;

	//�l
	chocoPoint_ = ValueManager::GetInstance().GetPoints();
	enemyPoint_ = ValueManager::GetInstance().GetEnemyD();


	
	if (chocoPoint_ >= 5)
	{
		Instantiate<GameClear>(this);
	}
	else
	{
		Instantiate<GameOver>(this);
	}
	
	Instantiate<Result_Text>(this);
	Instantiate<Result_Instruction>(this);
}

//�X�V
void ResultScene::Update()
{
}

//�`��
void ResultScene::Draw()
{
	//�w�i��
	trBackS_.position_.y = -0.4f;
	trBackS_.scale_ = XMFLOAT3(0.9f, 0.2f, 1.0f);
	Image::SetAlpha(hBackSmall_, 100);
	Image::SetTransform(hBackSmall_, trBackS_);
	Image::Draw(hBackSmall_);


	//Result����
	trResultN_.position_.y = 0.8f;
	trResultN_.scale_ = XMFLOAT3(0.4f, 0.4f, 1.0f);
	Image::SetTransform(hResultName_, trResultN_);
	Image::Draw(hResultName_);


	//Perfect����
	if (chocoPoint_ >= 5 && enemyPoint_ >= 10)
	{
		trPerfect_.position_.x = 0.2f;
		trPerfect_.position_.y = -0.55f;
		Image::SetTransform(hPerfect_, trPerfect_);
		Image::Draw(hPerfect_);
	}
}

//�J��
void ResultScene::Release()
{
}