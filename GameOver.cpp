#include "GameOver.h"
#include "Engine/Image.h"
#include "Engine/Audio.h"

//コンストラクタ
GameOver::GameOver(GameObject* parent)
    :GameObject(parent, "GameOver"), hGameOver_(-1), sGameOver_(-1)
{
}

//デストラクタ
GameOver::~GameOver()
{
}

//初期化
void GameOver::Initialize()
{
    //画像データのロード
    hGameOver_ = Image::Load("Image/gameOver.png");
    assert(hGameOver_ >= 0);

    //サウンドデータのロード
    sGameOver_ = Audio::Load("Sound/gameOver.wav");
    assert(sGameOver_ >= 0);

    Audio::Play(sGameOver_);
}

//更新
void GameOver::Update()
{
}

//描画
void GameOver::Draw()
{
    Image::SetTransform(hGameOver_, transform_);
    Image::Draw(hGameOver_);
}

//開放
void GameOver::Release()
{
}