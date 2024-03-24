#include "TitleLogo.h"
#include "Engine/Image.h"

//コンストラクタ
TitleLogo::TitleLogo(GameObject* parent)
    :GameObject(parent, "TitleLogo"), hLogo_(-1)
{
}

//デストラクタ
TitleLogo::~TitleLogo()
{
}

//初期化
void TitleLogo::Initialize()
{
	//画像データのロード
	//タイトルロゴ
	hLogo_ = Image::Load("titleLogo.png");
	assert(hLogo_ >= 0);

	logoTr_.position_.y += 0.5f;
}

//更新
void TitleLogo::Update()
{
}

//描画
void TitleLogo::Draw()
{
	//タイトルロゴ
	Image::SetTransform(hLogo_, logoTr_);
	Image::Draw(hLogo_);
}

//開放
void TitleLogo::Release()
{
}