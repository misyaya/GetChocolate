#pragma once
#include "Engine/GameObject.h"

//罠を管理するクラス
class Trap : public GameObject
{
    //モデル
    int hTrap_;

    //モデルの状態
    int state_;

    enum {
        WAIT = 0,
        DOWN,
        UP
    };

    //上下動きに関わる値
    float speed_;
    bool movingUp_;

    float fps_; //FPSと掛ける用の値
    float up_;
    float down_;

public:
    //コンストラクタ
    Trap(GameObject* parent);

    //デストラクタ
    ~Trap();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};