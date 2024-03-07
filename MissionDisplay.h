#pragma once
#include "Engine/GameObject.h"

//ミッション表示を管理するクラス
class MissionDisplay : public GameObject
{

public:
    //コンストラクタ
    MissionDisplay(GameObject* parent);

    //デストラクタ
    ~MissionDisplay();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};