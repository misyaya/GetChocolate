#pragma once
#include "Engine/GameObject.h"

//タイトル背景を管理するクラス
class Title_Back : public GameObject
{
    int hBack_;    //背景

    Transform backTr_;

public:
    //コンストラクタ
    Title_Back(GameObject* parent);

    //デストラクタ
    ~Title_Back();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};