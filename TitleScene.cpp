#include "TitleScene.h"
#include "Back_Title.h"
#include "TitleLogo.h"
#include "StartButton.h"
#include "ValueManager.h"


//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene")
{
}

//初期化
void TitleScene::Initialize()
{
	Instantiate<Back_Title>(this);
	Instantiate<TitleLogo>(this);
	Instantiate<StartButton>(this);

	ValueManager::GetInstance().ResetPoints();
	ValueManager::GetInstance().ResetEnemyD();
}

//更新
void TitleScene::Update()
{
}

//描画
void TitleScene::Draw()
{	
}

//開放
void TitleScene::Release()
{
}