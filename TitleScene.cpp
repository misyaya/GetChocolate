#include "TitleScene.h"
#include "Title_Image.h"
#include "ValueManager.h"


//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene")
{
}

//初期化
void TitleScene::Initialize()
{
	Instantiate<Title_Image>(this);
	
	//値のリセット
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