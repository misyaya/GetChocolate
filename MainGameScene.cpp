#include "MainGameScene.h"
#include "Engine/Model.h"

//コンストラクタ
MainGameScene::MainGameScene(GameObject * parent)
	: GameObject(parent, "MainGameScene"),hModel_(-1)
{
}

//初期化
void MainGameScene::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Box.fbx");
	assert(hModel_ >= 0);
}

//更新
void MainGameScene::Update()
{
}

//描画
void MainGameScene::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void MainGameScene::Release()
{
}
