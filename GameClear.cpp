#include "GameClear.h"
#include "Engine/Image.h"
#include "Engine/Audio.h"

//コンストラクタ
GameClear::GameClear(GameObject* parent)
    :GameObject(parent, "GameClear"), hGameClear_(-1), sGameClear_(-1)
{
}

//デストラクタ
GameClear::~GameClear()
{
}

//初期化
void GameClear::Initialize()
{
    //画像データのロード
    hGameClear_ = Image::Load("Image/gameClear.png");
    assert(hGameClear_ >= 0);

    //サウンドデータのロード
    sGameClear_ = Audio::Load("Sound/gameClear.wav");
    assert(sGameClear_ >= 0);

    Audio::Play(sGameClear_);
}

//更新
void GameClear::Update()
{
}

//描画
void GameClear::Draw()
{
    Image::SetTransform(hGameClear_, transform_);
    Image::Draw(hGameClear_);
}

//開放
void GameClear::Release()
{
}