#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class LifeGauge : public GameObject
{
private:
    int hPictGauge_;    //画像番号(ゲージ本体)
    int hPictFrame_;    //画像番号(ゲージフレーム)

    float nowHp_;    //今の値
    float maxHp_;  //最大値
    const float minHp_ = 0.0f;  //最小値
    float aniHp_;   //表示用の値
    int ImageWidth;     //ゲージ本体画像の幅
    int ImageHeight;    //ゲージ本体画像の高さ

    bool flag = true;
    float power = 0;


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

    //HP設定
    void SetHp(float _nowHp, int _maxHp);

    //ゲージの位置設定
    void SetPosition(float x, float y, float z);

    //ゲージの向き設定
    void SetRotate(float x, float y, float z);

    //値の加減算
    void AddValue(float v);

    //値のセット
    void SetValue(float v);

    //現在のHP取得
    float GetValue();
};