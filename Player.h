#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "Floor.h"

//プレイヤーを管理するクラス
class Player : public GameObject
{
private:
    //モデル
   int hModel_;   

   //サウンド
   int sWalk_;      //足音
   int sDamage_;    //ダメージ音
   int sInvin_;     //無敵時間中の接敵
   int sChocoGet_;  //チョコレートを入手
   int sHitWall_;   //壁に接触

   //各種値
   int hPictHp_;  //
   int hB_;
   int nowHp_;    //現在のHP
   int maxHp_;    //最大HP
  
   int chocoPoint_; //チョコレート獲得数
   int enemyPoint_; //エネミー撃破数

   XMFLOAT3 prevPosition_;  //直前までいた位置

   //情報
   Transform tentative;
   Transform front;
   Transform hpTr_;
   
   //HP表示
   Text* pText;
   Text* pTextHp;

   //チョコレート獲得数表示
   Text* pTextC;
   Text* pChoco;

   //エネミー撃破数
   Text* pTextE;
   Text* pEnemy;

   int situation = 0;


   //無敵判定
   enum class InvincibilityState
   {
       Normal,
       Invincible
   };
   float invinTime;
   const float invinDuration = 5.0f * 60.0f;
   InvincibilityState invinState;
   float deltaTime;

   Floor* pFloor_;

 

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