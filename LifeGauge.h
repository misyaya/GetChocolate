#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class LifeGauge : public GameObject
{
private:
    int hPictGauge_;    //画像番号(ゲージの中身)
    int hPictFrame_;    //画像番号(ゲージの外枠)

    float nowHp;    //今の値
    const float maxHp_ = 1.0f;  //最大値
    float aniHp_;   //表示用の値
    int ImageWidth;     //ゲージ画像の幅
    int ImageHeight;    //ゲージ画像の高さ

    bool flag = true;
    float power = 0;
    float scalex = 1.3f;

    float MIN = 0.0f;
    float MAX = 1.0f;

public:

    //コンストラクタ
    LifeGauge(GameObject* parent);

    //デストラクタ
    ~LifeGauge();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //位置
    void SetPosition(float x, float y, float z);

    //値を加減算する
    void AddValue(float v);

    //
    void SetValue(float v);

    float GetValue();
};