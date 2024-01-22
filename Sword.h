#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Sword : public GameObject
{
    int sword_;
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
};