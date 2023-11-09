#include "MainGameScene.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"

//コンストラクタ
MainGameScene::MainGameScene(GameObject * parent)
	: GameObject(parent, "MainGameScene"),hModel_(-1)
{
}

//初期化
void MainGameScene::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Sample.fbx");
	assert(hModel_ >= 0);
}

//更新
void MainGameScene::Update()
{
	
	if (Input::IsKey(DIK_W))
	{
		kari.position_.z += 0.1f;
	}

	if (Input::IsKey(DIK_S))
	{
		kari.position_.z -= 0.1f;
	}


	if (Input::IsKey(DIK_D))
	{
		kari.position_.x += 0.1f;
	}
	
	if (Input::IsKey(DIK_A))
	{
		kari.position_.x -= 0.1f;
	}

	Camera::SetPosition(XMFLOAT3(kari.position_.x, 3, -8));
	Camera::SetTarget(XMFLOAT3(kari.position_.x, 2, 0));
}

//描画
void MainGameScene::Draw()
{
	Model::SetTransform(hModel_, kari);
	Model::Draw(hModel_);
}

//開放
void MainGameScene::Release()
{
}
