#include "GameClear.h"
#include "Engine/Image.h"

//�R���X�g���N�^
GameClear::GameClear(GameObject* parent)
    :GameObject(parent, "GameClear"), hGameClear_(-1)
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
    hGameClear_ = Image::Load("gameClear.png");
    assert(hGameClear_ >= 0);
}

//�X�V
void GameClear::Update()
{
}

//�`��
void GameClear::Draw()
{
    Image::SetTransform(hGameClear_, transform_);
    Image::Draw(hGameClear_);
}

//�J��
void GameClear::Release()
{
}