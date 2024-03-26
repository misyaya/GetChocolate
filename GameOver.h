#pragma once
#include "Engine/GameObject.h"

//GameOver...の画像を管理するクラス
class GameOver : public GameObject
{
    //画像データ
    int hGameOver_;

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