#include "Title_Logo.h"
#include "Engine/Image.h"

//コンストラクタ
Title_Logo::Title_Logo(GameObject* parent)
    :GameObject(parent, "Title_Logo"), hLogo_(-1)
{
}

//デストラクタ
Title_Logo::~Title_Logo()
{
}

//初期化
void Title_Logo::Initialize()
{
	//画像データのロード
	//タイトルロゴ
	hLogo_ = Image::Load("Image/title_Logo.png");
	assert(hLogo_ >= 0);

	logoTr_.position_.y += 0.5f;
}

//更新
void Title_Logo::Update()
{
}

//描画
void Title_Logo::Draw()
{
	//タイトルロゴ
	Image::SetTransform(hLogo_, logoTr_);
	Image::Draw(hLogo_);
}

//開放
void Title_Logo::Release()
{
}