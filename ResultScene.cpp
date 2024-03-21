#include "ResultScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Image.h"
#include "ValueManager.h"
#include "Engine/Audio.h"

//コンストラクタ
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"), pTextE(nullptr), pEnemy(nullptr), pTextC(nullptr), pChoco(nullptr),
	sGameSet_(-1), hBack_(-1), hGameClear_(-1)
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

	//GameClear文字
	hGameClear_ = Image::Load("GameClear.png");
	assert(hGameClear_ >= 0);

	transform_.position_.x = transform_.position_.x + 0.1f;

	Audio::Play(sGameSet_);
}

//更新
void ResultScene::Update()
{
	//スペースキーが押されていたら
	if (Input::IsKey(DIK_RETURN))
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

	//Image::SetTransform(hGameClear_, transform_);
	//Image::Draw(hGameClear_);

	
	//HP　数字
	pTextE->Draw(30, 30, "RESULT!");
	//pECount->Draw(30, 90, eCount_);


	chocoPoint_ = ValueManager::GetInstance().GetPoints();
	pTextC->Draw(550, 300, "CH"); 
	pChoco->Draw(600, 300, chocoPoint_);

	enemyPoint_ = ValueManager::GetInstance().GetEnemyD();
	pTextE->Draw(550, 360, "EN");
	pEnemy->Draw(600, 360, enemyPoint_);
	
}

//開放
void ResultScene::Release()
{
}