#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"


//リザルトシーンを管理するクラス
class ResultScene : public GameObject
{
	Text* pTextE;
	Text* pEnemy; //Enemyを倒した数

	Text* pTextC;
	Text* pChoco;

	int chocoPoint_;
	int enemyPoint_;

	//サウンド
	int sGameClear_;
	int sGameOver_;

	//画像データ
	int hBack_;    
	int hBackSmall_;
	int hResultName_;
	int hPerfect_;
	int hGameClear_;

	//画像の位置情報等
	Transform trBackS_;
	Transform trResultN_;
	Transform trPerfect_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	ResultScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};