#pragma once
#include "Engine/GameObject.h"

//リザルトのキー操作を管理するクラス
class Result_Instruction : public GameObject
{
    int hButton_;  //ボタン
    bool pushed; // 押されているか

    XMFLOAT3 center; //ボタンの中心座標(画面座標)
    XMFLOAT3 size; //ボタンの画像サイズ

    Transform buttonTr_;
    int alpha_;
    int shading_;

    XMFLOAT3 mouse;

public:
    //コンストラクタ
    Result_Instruction(GameObject* parent);

    //デストラクタ
    ~Result_Instruction();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //ボタンを押したか、押してないか
    void Push(bool pushed);

    //マウスボタン内に入っているか
    bool MouseInArea(XMFLOAT3 mousePos);

    void SetPosition(int x, int y);
};