#pragma once
#include "Engine/GameObject.h"
#include <string>

using std::string;

//ミッションを管理するクラス
class Mission : public GameObject
{
    struct mission {
        int num;
        string name;
        bool flag;
    };

    int minum_;

public:
    //コンストラクタ
    Mission(GameObject* parent);

    //デストラクタ
    ~Mission();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};