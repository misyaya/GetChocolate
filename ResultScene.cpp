#include "ResultScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "EnemyManager.h"
#include "Engine/Image.h"

//�R���X�g���N�^
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"),pText(nullptr),pECount(nullptr),hBack_(-1)
{
}

//������
void ResultScene::Initialize()
{
	pText = new Text;
	pText->Initialize();

	pECount = new Text;
	pECount->Initialize();

	//�摜�f�[�^�̃��[�h
	//�w�i
	hBack_ = Image::Load("TitleBack.png");
	assert(hBack_ >= 0);
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
	//�w�i
	Image::SetAlpha(hBack_, 128);
	Image::SetTransform(hBack_, transform_);
	Image::Draw(hBack_);

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