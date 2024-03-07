#pragma once
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class MainGameScene : public GameObject
{
	
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	MainGameScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//終了条件を満たしたとき
	void MainGameEnd();
};