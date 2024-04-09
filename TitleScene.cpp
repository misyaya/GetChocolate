#include "TitleScene.h"
#include "Title_Back.h"
#include "Title_Instruction.h"
#include "Title_Logo.h"
#include "ValueManager.h"


//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene")
{
}

//初期化
void TitleScene::Initialize()
{
	Instantiate<Title_Back>(this);
	Instantiate<Title_Instruction>(this);
	Instantiate<Title_Logo>(this);


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