#include "GameClear.h"
#include "Engine/Image.h"

//コンストラクタ
GameClear::GameClear(GameObject* parent)
    :GameObject(parent, "GameClear"), hGameClear_(-1)
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
    hGameClear_ = Image::Load("gameClear.png");
    assert(hGameClear_ >= 0);
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