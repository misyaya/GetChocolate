#include "ResultScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Image.h"
#include "ValueManager.h"
#include "Engine/Audio.h"
#include "PressSpace.h"
#include "GameClear.h"
#include "GameOver.h"

//コンストラクタ
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"), pTextE(nullptr), pEnemy(nullptr), pTextC(nullptr), pChoco(nullptr),
	sGameClear_(-1), sGameOver_(-1), hBack_(-1), hBackSmall_(-1), hResultName_(-1), hPerfect_(-1), hGameClear_(-1)
{
}

//初期化
void ResultScene::Initialize()
{
	pTextE = new Text;
	pTextE->Initialize();

	pEnemy = new Text;
	pEnemy->Initialize();

	pTextC = new Text;
	pTextC->Initialize();
	
	pChoco = new Text;
	pChoco->Initialize();


	//サウンドデータのロード
	//GameClear時
	sGameClear_ = Audio::Load("GameSet.wav");
	assert(sGameClear_ >= 0);

	//GameOver時
	sGameOver_ = Audio::Load("gameOver.wav");
	assert(sGameOver_ >= 0);

	//画像データのロード
	//背景
	hBack_ = Image::Load("TitleBack.png");
	assert(hBack_ >= 0);

	//背景小
	hBackSmall_ = Image::Load("resultBack.png");
	assert(hBackSmall_ >= 0);

	//Result文字
	hResultName_ = Image::Load("resultName.png");
	assert(hResultName_ >= 0);

	//Perfect文字
	hPerfect_ = Image::Load("perfect.png");
	assert(hPerfect_ >= 0);

	//GameClear文字
	//hGameClear_ = Image::Load("GameClear.png");
	//assert(hGameClear_ >= 0);

	transform_.position_.x = transform_.position_.x + 0.1f;

	

	//値
	chocoPoint_ = ValueManager::GetInstance().GetPoints();
	enemyPoint_ = ValueManager::GetInstance().GetEnemyD();
	
	if (chocoPoint_ >= 5)
	{
		Instantiate<GameClear>(this);
		Audio::Play(sGameClear_);
	}
	else
	{
		Instantiate<GameOver>(this);
		Audio::Play(sGameOver_);
	}
	Instantiate<PressSpace>(this);
}

//更新
void ResultScene::Update()
{
	//スペースキーが押されていたら
	if (Input::IsKeyUp(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
	
}

//描画
void ResultScene::Draw()
{
	//背景
	Image::SetAlpha(hBack_, 128);
	Image::SetTransform(hBack_, transform_);
	Image::Draw(hBack_);


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

	//GameClear文字
	//Image::SetTransform(hGameClear_, transform_);
	//Image::Draw(hGameClear_);


	//Perfect文字
	if (chocoPoint_ >= 5 && enemyPoint_ >= 10)
	{
		trPerfect_.position_.x = 0.2f;
		trPerfect_.position_.y = -0.55f;
		Image::SetTransform(hPerfect_, trPerfect_);
		Image::Draw(hPerfect_);
	}
	
	//HP　数字
	//pTextE->Draw(30, 30, "RESULT!");
	//pECount->Draw(30, 90, eCount_);

	//値表示
	pTextC->Draw(500, 500, "CH");
	pChoco->Draw(580, 500, chocoPoint_);
	pTextE->Draw(700, 500, "EN");
	pEnemy->Draw(780, 500, enemyPoint_);
	
}

//開放
void ResultScene::Release()
{
}