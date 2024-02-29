#pragma once
#include "Engine/GameObject.h"
#include "Player.h"

//エネミーを管理するクラス
class Enemy : public GameObject
{
    int enemy_;
    float enemySpeed_;
 

    Player* pl;
    
    XMFLOAT3 playerPos_;
   
    float differenceX;
    float differenceY;
    float differenceZ;

    //エネミーを倒した数
    int kill_;

public:
    //コンストラクタ
    Enemy(GameObject* parent);

    //デストラクタ
    ~Enemy();

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

    void SetPlayerPos(XMFLOAT3 _playerPos);

    void SetPlayer(Player* player);

    void PlayerChase();

    int GetKill();

    void SetEnemyPos(XMFLOAT3 _enemyPos);

};