#include "TitleScene.h"
#include "Title_Back.h"
#include "Title_Instruction.h"
#include "Title_Logo.h"
#include "ValueManager.h"


//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene")
{
}

//������
void TitleScene::Initialize()
{
	Instantiate<Title_Back>(this);
	Instantiate<Title_Instruction>(this);
	Instantiate<Title_Logo>(this);


	ValueManager::GetInstance().ResetPoints();
	ValueManager::GetInstance().ResetEnemyD();
}

//�X�V
void TitleScene::Update()
{
}

//�`��
void TitleScene::Draw()
{	
}

//�J��
void TitleScene::Release()
{
}