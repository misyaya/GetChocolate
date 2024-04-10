#include "ResultScene.h"
#include "Engine/Image.h"
#include "Result_Text.h"
#include "Result_Image.h"
#include "GameClear.h"
#include "GameOver.h"
#include "ValueManager.h"

//コンストラクタ
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"),
	chocoPoint_(0), enemyPoint_(0), criteria_(5)
{
}

//初期化
void ResultScene::Initialize()
{
	Instantiate<Result_Image>(this);
	Instantiate<Result_Text>(this);

	//値セット
	chocoPoint_ = ValueManager::GetInstance().GetPoints();
	enemyPoint_ = ValueManager::GetInstance().GetEnemyD();

	//クリア条件を満たしていたらGameClearを呼び出す、そうでなければGameOverを呼び出す
	if (chocoPoint_ >= criteria_)
	{
		Instantiate<GameClear>(this);
	}
	else
	{
		Instantiate<GameOver>(this);
	}
}

//更新
void ResultScene::Update()
{
}

//描画
void ResultScene::Draw()
{
	

}

//開放
void ResultScene::Release()
{
}