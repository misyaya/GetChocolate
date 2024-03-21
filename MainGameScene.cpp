#include "MainGameScene.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"
#include "Player.h"
#include "Floor.h"
#include "Enemy.h"
#include "Chocolate.h"




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
	


	for (int i = 0; i < 10; i++)
	{
		if(i % 2 ==0)
		{
			Instantiate<Chocolate>(this);
		}

		Instantiate<Enemy>(this);
	}
	
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

void MainGameScene::MainGameEnd()
{
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_RESULT);
}
