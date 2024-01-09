#pragma once
#include "Engine/GameObject.h"
#include "Player.h"

//◆◆◆を管理するクラス
class Enemy : public GameObject
{
    int enemy_;
    float enemySpeed_;
    Transform enemyTr;

    Player* pl;
    
    XMFLOAT3 playerPos_;
    float plX;
    float plY;
    float plZ;

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

};