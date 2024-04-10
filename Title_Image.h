#pragma once
#include "Engine/GameObject.h"

//タイトルシーンに表示する画像を管理するクラス
class Title_Image : public GameObject
{
    //画像
    int hBack_;  //背景
    int hLogo_;  //タイトルロゴ
    int hKey_;   //キー操作誘導



    //画像情報
    Transform trBack_;  //hBack_情報
    Transform trLogo_;  //hLogo_情報
    Transform trKey_;   //hKey_操作誘導情報



    //画像透明度関連
    //キー操作誘導
    int keyAlpha_;    //hKey_透明度
    int keyShading_;  //hKey_透明度の加減

public:
    //コンストラクタ
    Title_Image(GameObject* parent);

    //デストラクタ
    ~Title_Image();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};