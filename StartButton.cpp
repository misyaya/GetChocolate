#include "StartButton.h"
#include "Engine/Image.h"

//コンストラクタ
StartButton::StartButton(GameObject* parent)
    :GameObject(parent, "StartButton"), hButton_(-1)
{
}

//デストラクタ
StartButton::~StartButton()
{
}

//初期化
void StartButton::Initialize()
{
	//ボタン
	hButton_ = Image::Load("TitleButton.png");
	assert(hButton_ >= 0);

	buttonTr_.scale_ = XMFLOAT3(0.5f, 0.5f, 0.5f);
	buttonTr_.position_.y -= 0.5f;
}

//更新
void StartButton::Update()
{
}

//描画
void StartButton::Draw()
{
	//ボタン
	Image::SetTransform(hButton_, buttonTr_);
	Image::Draw(hButton_);
}

//開放
void StartButton::Release()
{
}