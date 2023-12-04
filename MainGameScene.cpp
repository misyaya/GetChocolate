#include "MainGameScene.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Player.h"
#include "Floor.h"
#include "Enemy.h"
#include "LifeGauge.h"

//�R���X�g���N�^
MainGameScene::MainGameScene(GameObject * parent)
	: GameObject(parent, "MainGameScene")
{
}

//������
void MainGameScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Floor>(this);
	Instantiate<Enemy>(this);
	LifeGauge* g = Instantiate<LifeGauge>(this);
	g->SetHp(100.0f, 100.0f);
	g->SetPosition(-0.9f, 0.8f, 10.0f);
	
	
}

//�X�V
void MainGameScene::Update()
{
}

//�`��
void MainGameScene::Draw()
{
}

//�J��
void MainGameScene::Release()
{
}
