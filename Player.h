#pragma once
#include "Engine/GameObject.h"
#include "LifeGauge.h"
#include "Sword.h"
#include "Engine/Text.h"

//◆◆◆を管理するクラス
class Player : public GameObject
{
   int hModel_;    //モデル番号4
   int hPictHp_;
   int hB_;
   int nowHp_;
   int maxHp_;

   int time_;

   Transform kari;
   Transform front;
   Transform hpTr_;
   
   Text* pText;

   int situation = 0;
   enum 
   {
       WAIT = 0,
       DAMAGE
   };
    
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

    void SetInvulnerable();

    void SetPlayrPos(XMFLOAT3 _position);

    XMFLOAT3 GetPlayerPos();
};