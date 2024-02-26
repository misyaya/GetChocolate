#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class StartButton : public GameObject
{
    int hButton_;  //ボタン

    Transform buttonTr_;

public:
    //コンストラクタ
    StartButton(GameObject* parent);

    //デストラクタ
    ~StartButton();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};