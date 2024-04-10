#pragma once
#include "Engine/GameObject.h"

//リザルトシーンの画像を管理するクラス(GameClearとGameOverは別クラス管理)
class Result_Image : public GameObject
{
    //画像
    int hBack_;        //背景
    int hBackLittle_;  //背景(小)
    int hResultName_;  //RESULT!と書いてある画像
    int hKey_;         //キー操作誘導

    //画像情報
    Transform trBack_;     //hBack_情報
    Transform trBackL_;    //hBackLittle_情報
    Transform trResultN_;  //hResultName_情報
    Transform trKey_;      //hKey_情報

    //画像透明度関連
    //キー操作誘導
    int keyAlpha_;    //hKey_透明度
    int keyShading_;  //hKey_透明度の加減

public:
    //コンストラクタ
    Result_Image(GameObject* parent);

    //デストラクタ
    ~Result_Image();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};