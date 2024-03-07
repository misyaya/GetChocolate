#include "ResultScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "EnemyManager.h"


//�R���X�g���N�^
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"),pText(nullptr),pECount(nullptr)
{
}

//������
void ResultScene::Initialize()
{
	pText = new Text;
	pText->Initialize();

	pECount = new Text;
	pECount->Initialize();
}

//�X�V
void ResultScene::Update()
{
	//�X�y�[�X�L�[��������Ă�����
	if (Input::IsKey(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}	
}

//�`��
void ResultScene::Draw()
{
	EnemyManager* EManager = new EnemyManager();
	int eCount_ = EManager->GetDeadCount();
	
	//HP�@����
	pText->Draw(30, 30, "RESULT");
	pECount->Draw(30, 90, eCount_);
}

//�J��
void ResultScene::Release()
{
}