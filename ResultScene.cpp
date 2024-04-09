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

//コンストラクタ
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"),
	hBackSmall_(-1), hResultName_(-1), hPerfect_(-1), hGameClear_(-1)
{
}

//初期化
void ResultScene::Initialize()
{
	Instantiate<Result_Back>(this);

	//画像データのロード
	//背景小
	hBackSmall_ = Image::Load("Image/result_BackLittle.png");
	assert(hBackSmall_ >= 0);

	//Result文字
	hResultName_ = Image::Load("Image/resultName.png");
	assert(hResultName_ >= 0);

	//Perfect文字
	hPerfect_ = Image::Load("Image/perfect.png");
	assert(hPerfect_ >= 0);


	transform_.position_.x = transform_.position_.x + 0.1f;

	//値
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

//更新
void ResultScene::Update()
{
}

//描画
void ResultScene::Draw()
{
	//背景小
	trBackS_.position_.y = -0.4f;
	trBackS_.scale_ = XMFLOAT3(0.9f, 0.2f, 1.0f);
	Image::SetAlpha(hBackSmall_, 100);
	Image::SetTransform(hBackSmall_, trBackS_);
	Image::Draw(hBackSmall_);


	//Result文字
	trResultN_.position_.y = 0.8f;
	trResultN_.scale_ = XMFLOAT3(0.4f, 0.4f, 1.0f);
	Image::SetTransform(hResultName_, trResultN_);
	Image::Draw(hResultName_);


	//Perfect文字
	if (chocoPoint_ >= 5 && enemyPoint_ >= 10)
	{
		trPerfect_.position_.x = 0.2f;
		trPerfect_.position_.y = -0.55f;
		Image::SetTransform(hPerfect_, trPerfect_);
		Image::Draw(hPerfect_);
	}
}

//開放
void ResultScene::Release()
{
}