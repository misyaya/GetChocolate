#include "GameClear.h"
#include "Engine/Image.h"
#include "Engine/Audio.h"
#include "ValueManager.h"

//コンストラクタ
GameClear::GameClear(GameObject* parent)
    :GameObject(parent, "GameClear"),
    hGameClear_(-1), hPerfect_(-1), sGameClear_(-1),
    chocoPoint_(0), enemyPoint_(0)
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
    //GameClear!!
    hGameClear_ = Image::Load("Image/gameClear.png");
    assert(hGameClear_ >= 0);

    //Perfect!
    hPerfect_ = Image::Load("Image/perfect.png");
    assert(hPerfect_ >= 0);

    //サウンドデータのロード
    sGameClear_ = Audio::Load("Sound/gameClear.wav");
    assert(sGameClear_ >= 0);



    //画像情報
    //GameClear!!
    
    
    //Perfect!
    trPerfect_.position_.x = 0.2f;
    trPerfect_.position_.y = -0.55f;


    //サウンド鳴らす
    Audio::Play(sGameClear_);



    //値セット
    chocoPoint_ = ValueManager::GetInstance().GetPoints();
    enemyPoint_ = ValueManager::GetInstance().GetEnemyD();
}

//更新
void GameClear::Update()
{
}

//描画
void GameClear::Draw()
{
    Image::SetTransform(hGameClear_, trClear_);
    Image::Draw(hGameClear_);


    //Perfect文字     　↓チョコ、エネミーの呼び出し数を持ってくるようにする
    /*if (chocoPoint_ >= 5 && enemyPoint_ >= 10)
    {
        Image::SetTransform(hPerfect_, trPerfect_);
        Image::Draw(hPerfect_);
    }*/
}

//開放
void GameClear::Release()
{
}