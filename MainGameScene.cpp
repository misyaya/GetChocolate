#include "MainGameScene.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"
#include "Player.h"
#include "Floor.h"
#include "Enemy.h"
#include "Chocolate.h"




//コンストラクタ
MainGameScene::MainGameScene(GameObject * parent)
	: GameObject(parent, "MainGameScene")
{
}

//初期化
void MainGameScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Floor>(this);
	


	for (int i = 0; i < 10; i++)
	{
		if(i % 2 ==0)
		{
			Instantiate<Chocolate>(this);
		}

		Instantiate<Enemy>(this);
	}
	
}

//更新
void MainGameScene::Update()
{
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
