#pragma once
#include "Engine/GameObject.h"

//リザルトシーンを管理するクラス
class ResultScene : public GameObject
{
	//各種値
	int chocoPoint_;  //チョコレート獲得数
	int enemyPoint_;  //エネミー撃破数
	int criteria_;    //クリア基準

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