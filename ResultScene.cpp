#include "ResultScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Image.h"
#include "ValueManager.h"
#include "Engine/Audio.h"

//コンストラクタ
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"), pTextE(nullptr), pEnemy(nullptr), pTextC(nullptr), pChoco(nullptr),
	sGameSet_(-1), hBack_(-1), hBackSmall_(-1), hResultName_(-1), hPerfect_(-1), hGameClear_(-1)
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
	sGameSet_ = Audio::Load("GameSet.wav");
	assert(sGameSet_ >= 0);

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

	Audio::Play(sGameSet_);
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
	//リザルト値
	chocoPoint_ = ValueManager::GetInstance().GetPoints();
	enemyPoint_ = ValueManager::GetInstance().GetEnemyD();
	

	//背景
	Image::SetAlpha(hBack_, 128);
	Image::SetTransform(hBack_, transform_);
	Image::Draw(hBack_);


	//背景小
	trBackS_.position_.y = 0.1f;
	trBackS_.scale_ = XMFLOAT3(0.9f, 0.7f, 1.0f);
	Image::SetAlpha(hBackSmall_, 200);
	Image::SetTransform(hBackSmall_, trBackS_);
	Image::Draw(hBackSmall_);


	//Result文字
	trResultN_.position_.y = 0.5f;
	trResultN_.scale_ = XMFLOAT3(0.5f, 0.5f, 1.0f);
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
	pTextC->Draw(600, 360, "CH");
	pChoco->Draw(680, 360, chocoPoint_);
	pTextE->Draw(600, 400, "EN");
	pEnemy->Draw(680, 400, enemyPoint_);
	
}

//開放
void ResultScene::Release()
{
}