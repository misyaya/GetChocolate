#pragma once
#include "Engine/GameObject.h"

enum
{
    TYPE_GRASS,
    TYPE_SOIL,
    TYPE_GRASSBOX,
    TYPE_MAX,
};


//ステージ床を管理するクラス
class Floor : public GameObject
{
    //モデル
    int hModel_[TYPE_MAX];    //モデル番号

    int** table_;

    int width_, height_;

public:
    //コンストラクタ
    Floor(GameObject* parent);

    //デストラクタ
    ~Floor();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    /// <summary>
    /// 指定した位置が通れるか通れないか
    /// </summary>
    /// <param name="x"></param>
    /// <param name="z"></param>
    /// <returns>通れない＝true/通れる=false</returns>
    bool IsWall(int x, int z);
};