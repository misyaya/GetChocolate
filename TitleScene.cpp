#include "TitleScene.h"
#include "Title_Image.h"
#include "ValueManager.h"


//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene")
{
}

//������
void TitleScene::Initialize()
{
	Instantiate<Title_Image>(this);
	
	//�l�̃��Z�b�g
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