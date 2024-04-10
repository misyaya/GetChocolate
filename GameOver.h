#pragma once
#include "Engine/GameObject.h"

//GameOverを管理するクラス
class GameOver : public GameObject
{
    //画像
    int hGameOver_;

    //サウンド
    int sGameOver_;

public:
    //コンストラクタ
    GameOver(GameObject* parent);

    //デストラクタ
    ~GameOver();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};