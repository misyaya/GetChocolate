#pragma once
#include "Engine/GameObject.h"

//チョコレートを管理するクラス
class Chocolate : public GameObject
{
    //モデル
    int hChoco_;

    //エフェクト
    int hEmit_;

public:
    //コンストラクタ
    Chocolate(GameObject* parent);

    //デストラクタ
    ~Chocolate();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject* pTarget) override;
};