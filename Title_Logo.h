#pragma once
#include "Engine/GameObject.h"

//タイトルロゴを管理するクラス
class Title_Logo : public GameObject
{
    int hLogo_;   //タイトルロゴ

    Transform logoTr_;

public:
    //コンストラクタ
    Title_Logo(GameObject* parent);

    //デストラクタ
    ~Title_Logo();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};