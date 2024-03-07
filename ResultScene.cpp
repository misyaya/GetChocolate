#include "ResultScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "EnemyManager.h"
#include "Engine/Image.h"

//コンストラクタ
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"),pText(nullptr),pECount(nullptr),hBack_(-1)
{
}

//初期化
void ResultScene::Initialize()
{
	pText = new Text;
	pText->Initialize();

	pECount = new Text;
	pECount->Initialize();

	//画像データのロード
	//背景
	hBack_ = Image::Load("TitleBack.png");
	assert(hBack_ >= 0);
}

//更新
void ResultScene::Update()
{
	//スペースキーが押されていたら
	if (Input::IsKey(DIK_SPACE))
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

	EnemyManager* EManager = new EnemyManager();
	int eCount_ = EManager->GetDeadCount();
	
	//HP　数字
	pText->Draw(30, 30, "RESULT");
	pECount->Draw(30, 90, eCount_);

	
}

//開放
void ResultScene::Release()
{
}