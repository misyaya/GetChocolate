#include "Title_Back.h"
#include "Engine/Image.h"
#include "Engine/Image.h"

//コンストラクタ
Title_Back::Title_Back(GameObject* parent)
    :GameObject(parent, "Title_Back"), hBack_(-1)
{
}

//デストラクタ
Title_Back::~Title_Back()
{
}

//初期化
void Title_Back::Initialize()
{
	//画像データのロード
	//背景
	hBack_ = Image::Load("Image/BackGround.png");
	assert(hBack_ >= 0);
}

//更新
void Title_Back::Update()
{
}

//描画
void Title_Back::Draw()
{
	//背景
	Image::SetTransform(hBack_, backTr_);
	Image::Draw(hBack_);
}

//開放
void Title_Back::Release()
{
}