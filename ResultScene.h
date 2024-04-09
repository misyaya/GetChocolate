#pragma once
#include "Engine/GameObject.h"


//リザルトシーンを管理するクラス
class ResultScene : public GameObject
{
	//各種値
	int chocoPoint_;
	int enemyPoint_;

	//画像
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