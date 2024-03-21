#include "TitleScene.h"
#include "Back_Title.h"
#include "TitleLogo.h"
#include "StartButton.h"
#include "ValueManager.h"


//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene")
{
}

//������
void TitleScene::Initialize()
{
	Instantiate<Back_Title>(this);
	Instantiate<TitleLogo>(this);
	Instantiate<StartButton>(this);

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