#pragma once
#include "Engine/GameObject.h"
#include  "LifeGauge.h"

//◆◆◆を管理するクラス
class Player : public GameObject
{
    int hModel_;    //モデル番号4
    int hPictHp_;
    Transform kari;
    Transform front;
    Transform hpTr_;
   
    int nowHp_;
   // LifeGauge* pLifeGauge = (LifeGauge*)FindObject("Gauge");
public:
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //当たり判定
    void OnCollision(GameObject* pTarget);

    void SetPlayrPos(XMFLOAT3 _position);

    XMFLOAT3 GetPlayerPos();
};