#pragma once
#include "Engine/GameObject.h"

//罠を管理するクラス
class Trap : public GameObject
{
    //モデル
    int hTrap_;

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