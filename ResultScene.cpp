#include "ResultScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Image.h"
#include "ValueManager.h"
#include "Engine/Audio.h"

//�R���X�g���N�^
ResultScene::ResultScene(GameObject* parent)
	: GameObject(parent, "ResultScene"), pTextE(nullptr), pEnemy(nullptr), pTextC(nullptr), pChoco(nullptr),
	sGameSet_(-1), hBack_(-1), hGameClear_(-1)
{
}

//������
void ResultScene::Initialize()
{
	pTextE = new Text;
	pTextE->Initialize();

	pEnemy = new Text;
	pEnemy->Initialize();

	pTextC = new Text;
	pTextC->Initialize();
	
	pChoco = new Text;
	pChoco->Initialize();


	//�T�E���h�f�[�^�̃��[�h
	sGameSet_ = Audio::Load("GameSet.wav");
	assert(sGameSet_ >= 0);

	//�摜�f�[�^�̃��[�h
	//�w�i
	hBack_ = Image::Load("TitleBack.png");
	assert(hBack_ >= 0);

	//GameClear����
	hGameClear_ = Image::Load("GameClear.png");
	assert(hGameClear_ >= 0);

	transform_.position_.x = transform_.position_.x + 0.1f;

	Audio::Play(sGameSet_);
}

//�X�V
void ResultScene::Update()
{
	//�X�y�[�X�L�[��������Ă�����
	if (Input::IsKey(DIK_RETURN))
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

	//Image::SetTransform(hGameClear_, transform_);
	//Image::Draw(hGameClear_);

	
	//HP�@����
	pTextE->Draw(30, 30, "RESULT!");
	//pECount->Draw(30, 90, eCount_);


	chocoPoint_ = ValueManager::GetInstance().GetPoints();
	pTextC->Draw(550, 300, "CH"); 
	pChoco->Draw(600, 300, chocoPoint_);

	enemyPoint_ = ValueManager::GetInstance().GetEnemyD();
	pTextE->Draw(550, 360, "EN");
	pEnemy->Draw(600, 360, enemyPoint_);
	
}

//�J��
void ResultScene::Release()
{
}