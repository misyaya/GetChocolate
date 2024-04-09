#include "GameOver.h"
#include "Engine/Image.h"
#include "Engine/Audio.h"

//�R���X�g���N�^
GameOver::GameOver(GameObject* parent)
    :GameObject(parent, "GameOver"), hGameOver_(-1), sGameOver_(-1)
{
}

//�f�X�g���N�^
GameOver::~GameOver()
{
}

//������
void GameOver::Initialize()
{
    //�摜�f�[�^�̃��[�h
    hGameOver_ = Image::Load("Image/gameOver.png");
    assert(hGameOver_ >= 0);

    //�T�E���h�f�[�^�̃��[�h
    sGameOver_ = Audio::Load("Sound/gameOver.wav");
    assert(sGameOver_ >= 0);

    Audio::Play(sGameOver_);
}

//�X�V
void GameOver::Update()
{
}

//�`��
void GameOver::Draw()
{
    Image::SetTransform(hGameOver_, transform_);
    Image::Draw(hGameOver_);
}

//�J��
void GameOver::Release()
{
}