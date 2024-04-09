#pragma once
#include "Engine/GameObject.h"

//GameClearを管理するクラス
class GameClear : public GameObject
{
    //画像
    int hGameClear_;

    //サウンド
    int sGameClear_;

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