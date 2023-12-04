#include "MainGameScene.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Player.h"
#include "Floor.h"
#include "Enemy.h"
#include "LifeGauge.h"

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
	Instantiate<Enemy>(this);
	LifeGauge* g = Instantiate<LifeGauge>(this);
	g->SetHp(100.0f, 100.0f);
	g->SetPosition(-0.9f, 0.8f, 10.0f);
	
	
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
