#include "MainGameScene.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Player.h"
#include "Floor.h"
#include "Enemy.h"
#include "Chocolate.h"
#include "Engine/SceneManager.h"



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
	Instantiate<Chocolate>(this);
	Instantiate<Sword>(this);


	for (int i = 0; i < 10; i++)
	{
		Instantiate<Enemy>(this);
	}
	
}

//更新
void MainGameScene::Update()
{
	//スペースキーが押されていたら
	if (Input::IsKey(DIK_K))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_RESULT);
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
