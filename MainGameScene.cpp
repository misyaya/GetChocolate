#include "MainGameScene.h"
#include "Engine/Model.h"

//�R���X�g���N�^
MainGameScene::MainGameScene(GameObject * parent)
	: GameObject(parent, "MainGameScene"),hModel_(-1)
{
}

//������
void MainGameScene::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Box.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void MainGameScene::Update()
{
}

//�`��
void MainGameScene::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void MainGameScene::Release()
{
}
