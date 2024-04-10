#include "GameClear.h"
#include "Engine/Image.h"
#include "Engine/Audio.h"
#include "ValueManager.h"

//�R���X�g���N�^
GameClear::GameClear(GameObject* parent)
    :GameObject(parent, "GameClear"),
    hGameClear_(-1), hPerfect_(-1), sGameClear_(-1),
    chocoPoint_(0), enemyPoint_(0)
{
}

//�f�X�g���N�^
GameClear::~GameClear()
{
}

//������
void GameClear::Initialize()
{
    //�摜�f�[�^�̃��[�h
    //GameClear!!
    hGameClear_ = Image::Load("Image/gameClear.png");
    assert(hGameClear_ >= 0);

    //Perfect!
    hPerfect_ = Image::Load("Image/perfect.png");
    assert(hPerfect_ >= 0);

    //�T�E���h�f�[�^�̃��[�h
    sGameClear_ = Audio::Load("Sound/gameClear.wav");
    assert(sGameClear_ >= 0);



    //�摜���
    //GameClear!!
    
    
    //Perfect!
    trPerfect_.position_.x = 0.2f;
    trPerfect_.position_.y = -0.55f;


    //�T�E���h�炷
    Audio::Play(sGameClear_);



    //�l�Z�b�g
    chocoPoint_ = ValueManager::GetInstance().GetPoints();
    enemyPoint_ = ValueManager::GetInstance().GetEnemyD();
}

//�X�V
void GameClear::Update()
{
}

//�`��
void GameClear::Draw()
{
    Image::SetTransform(hGameClear_, trClear_);
    Image::Draw(hGameClear_);


    //Perfect����     �@���`���R�A�G�l�~�[�̌Ăяo�����������Ă���悤�ɂ���
    /*if (chocoPoint_ >= 5 && enemyPoint_ >= 10)
    {
        Image::SetTransform(hPerfect_, trPerfect_);
        Image::Draw(hPerfect_);
    }*/
}

//�J��
void GameClear::Release()
{
}