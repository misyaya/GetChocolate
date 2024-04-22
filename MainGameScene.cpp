#include "MainGameScene.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"
#include "Player.h"
#include "Floor.h"
#include "Enemy.h"
#include "Chocolate.h"
#include "Sword.h"




//コンストラクタ
MainGameScene::MainGameScene(GameObject * parent)
	: GameObject(parent, "MainGameScene"),enemy_(10)
{
}

//初期化
void MainGameScene::Initialize()
{
	/*for (int i = 0; i < enemy_; i++)
	{
		if (i % 2 == 0)
		{
			Instantiate<Chocolate>(this);
		}

		Instantiate<Enemy>(this);
	}*/
	Instantiate<Floor>(this);
	Instantiate<Player>(this);
}

//更新
void MainGameScene::Update()
{
	//TitleSceneに戻る
	if (Input::IsKey(DIK_ESCAPE))
	{
		BackTitle();
	}
}

//描画
void MainGameScene::Draw()
{
}

//開放
void MainGameScene::Release()
{
}

void MainGameScene::MainGameEnd()
{
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_RESULT);
}

void MainGameScene::BackTitle()
{
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_TITLE);
}
