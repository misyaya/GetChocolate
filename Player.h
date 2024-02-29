#pragma once
#include "Engine/GameObject.h"
#include "LifeGauge.h"
#include "Sword.h"
#include "Engine/Text.h"

//プレイヤーを管理するクラス
class Player : public GameObject
{
private:
   int hModel_;    //モデル番号4
   int hPictHp_;
   int hB_;
   int nowHp_;
   int maxHp_;

   Transform kari;
   Transform front;
   Transform hpTr_;
   
   Text* pText;
   Text* pTextHp;

   int situation = 0;


   enum class InvincibilityState
   {
       Normal,
       Invincible
   };
    
   float invinTime;
   const float invinDuration = 5.0f*60.0f;
   InvincibilityState invinState;
   float deltaTime;

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

    //無敵時間
    void SetInvulnerable();

    //Player位置の設定
    void SetPlayerPos(XMFLOAT3 _position);

    //Player位置の取得
    XMFLOAT3 GetPlayerPos();

    //カメラ
    void UpdateCamera();

    //後ろに飛ぶ
    void MoveBackward(float _distance);
};