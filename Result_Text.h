#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//リザルトのテキスト表示をを管理するクラス
class Result_Text : public GameObject
{
    //各種値
    int chocoPoint_; //Chocolateを獲得した数
    int enemyPoint_; //Enemyを倒した数

    //テキスト表示
    Text* pTextE; //ENの文字表示
    Text* pEnemy; //enemyPoint_表示

    Text* pTextC; //CHの文字表示
    Text* pChoco; //chocoPoint_表示

public:
    //コンストラクタ
    Result_Text(GameObject* parent);

    //デストラクタ
    ~Result_Text();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};