#include "Result_Back.h"
#include "Engine/Image.h"
#include "Engine/Image.h"

//コンストラクタ
Result_Back::Result_Back(GameObject* parent)
	:GameObject(parent, "Result_Back"), hBack_(-1)
{
}

//デストラクタ
Result_Back::~Result_Back()
{
}

//初期化
void Result_Back::Initialize()
{
	//画像データのロード
	//背景
	hBack_ = Image::Load("Image/BackGround.png");
	assert(hBack_ >= 0);
}

//更新
void Result_Back::Update()
{
}

//描画
void Result_Back::Draw()
{
	//背景
	Image::SetAlpha(hBack_, 128);
	Image::SetTransform(hBack_, backTr_);
	Image::Draw(hBack_);
}

//開放
void Result_Back::Release()
{
}