#include "MainGameScene.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Player.h"
#include "Floor.h"
#include "Enemy.h"
#include "Chocolate.h"
#include "Engine/SceneManager.h"



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
	Instantiate<Chocolate>(this);
	Instantiate<Sword>(this);


	for (int i = 0; i < 10; i++)
	{
		Instantiate<Enemy>(this);
	}
	
}

//�X�V
void MainGameScene::Update()
{
	//�X�y�[�X�L�[��������Ă�����
	if (Input::IsKey(DIK_K))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_RESULT);
	}
}

//�`��
void MainGameScene::Draw()
{
}

//�J��
void MainGameScene::Release()
{
}
