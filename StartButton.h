#pragma once
#include "Engine/GameObject.h"

//スタートボタンを管理するクラス
class StartButton : public GameObject
{
    int hButton_;  //ボタン
    bool pushed; // 押されているか

    XMFLOAT3 center; //ボタンの中心座標(画面座標)
    XMFLOAT3 size; //ボタンの画像サイズ

    Transform buttonTr_;

    XMFLOAT3 mouse;

public:
    //コンストラクタ
    StartButton(GameObject* parent);

    //デストラクタ
    ~StartButton();

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