#include "GameOver.h"
#include "Engine/Image.h"

//コンストラクタ
GameOver::GameOver(GameObject* parent)
    :GameObject(parent, "GameOver"), hGameOver_(-1)
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
    hGameOver_ = Image::Load("gameOver.png");
    assert(hGameOver_ >= 0);
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