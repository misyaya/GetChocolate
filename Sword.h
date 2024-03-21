#pragma once
#include "Engine/GameObject.h"

//Swordを管理するクラス
class Sword : public GameObject
{
    int sword_;
    Transform front;
    int state_;
    bool attackflag_ = true;
    bool flag_ = true;
    bool atF = true;
    // クラスのメンバ変数
    bool isRotating = false;
    float targetRotation = 0.0f;
    float downSwingRotation = 90.0f;

    bool walkFlagL_ = true;
    bool walkFlagR_ = true;
    bool walkFlagF_ = true;
    bool walkFlagB_ = true;


    //剣(振り下ろす)
    int sSword_;

    int seconds_;
    int count_;

    enum {
        MOVE = 0,
        RETURN,
        ATTACK,
        WAIT
       
    };

public:
    //コンストラクタ
    Sword(GameObject* parent);

    //デストラクタ
    ~Sword();

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

    //
    void SetSwordTr(XMFLOAT3 _transform);

    //攻撃1
    void AttackSword();

    //攻撃2
    void AttackBeside();

    //攻撃終了1
    void FihishAttack();

    //Sword位置の設定
    void SetSwordPos(XMFLOAT3 _position);

    //Sword位置の取得
    XMFLOAT3 GetSwordPos();

    //後ろに飛ぶ
    void MoveBackward(float _distance);
}; 