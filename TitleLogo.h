#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class TitleLogo : public GameObject
{
    int hLogo_;   //タイトルロゴ

    Transform logoTr_;

public:
    //コンストラクタ
    TitleLogo(GameObject* parent);

    //デストラクタ
    ~TitleLogo();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};