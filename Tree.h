#pragma once
#include "Engine/GameObject.h"

//木を管理するクラス
class Tree : public GameObject
{
    //モデル
    int hTree_;

public:
    //コンストラクタ
    Tree(GameObject* parent);

    //デストラクタ
    ~Tree();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};