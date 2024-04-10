#include "ResultScene.h"
#include "Engine/Image.h"
#include "Result_Text.h"
#include "Result_Image.h"
#include "GameClear.h"
#include "GameOver.h"
#include "ValueManager.h"

//�R���X�g���N�^
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"),
	chocoPoint_(0), enemyPoint_(0), criteria_(5)
{
}

//������
void ResultScene::Initialize()
{
	Instantiate<Result_Image>(this);
	Instantiate<Result_Text>(this);

	//�l�Z�b�g
	chocoPoint_ = ValueManager::GetInstance().GetPoints();
	enemyPoint_ = ValueManager::GetInstance().GetEnemyD();

	//�N���A�����𖞂����Ă�����GameClear���Ăяo���A�����łȂ����GameOver���Ăяo��
	if (chocoPoint_ >= criteria_)
	{
		Instantiate<GameClear>(this);
	}
	else
	{
		Instantiate<GameOver>(this);
	}
}

//�X�V
void ResultScene::Update()
{
}

//�`��
void ResultScene::Draw()
{
	

}

//�J��
void ResultScene::Release()
{
}