#include "ResultScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"


//�R���X�g���N�^
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"),pText(nullptr)
{
}

//������
void ResultScene::Initialize()
{
	pText = new Text;
	pText->Initialize();
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
	//HP�@����
	pText->Draw(30, 30, "RESULT");
	
}

//�J��
void ResultScene::Release()
{
}