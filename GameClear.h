#pragma once
#include "Engine/GameObject.h"

//GameClearを管理するクラス
class GameClear : public GameObject
{
    //画像
    int hGameClear_;  //GameClear!!の文字
    int hPerfect_;    //Perfect!の文字



    //サウンド
    int sGameClear_;  //このクラスが呼びだされた時に鳴る



    //画像情報
    Transform trClear_;    //hGameClear_情報
    Transform trPerfect_;  //hPerfect_情報



    //各種値
    int chocoPoint_;  //チョコレート獲得数
    int enemyPoint_;  //エネミー撃破数

public:
    //コンストラクタ
    GameClear(GameObject* parent);

    //デストラクタ
    ~GameClear();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};