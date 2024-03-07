#include "Back_Title.h"
#include "Engine/Image.h"
#include "Engine/Image.h"

//コンストラクタ
Back_Title::Back_Title(GameObject* parent)
    :GameObject(parent, "Back_Title"), hBack_(-1)
{
}

//デストラクタ
Back_Title::~Back_Title()
{
}

//初期化
void Back_Title::Initialize()
{
	//画像データのロード
	//背景
	hBack_ = Image::Load("TitleBack.png");
	assert(hBack_ >= 0);
}

//更新
void Back_Title::Update()
{
}

//描画
void Back_Title::Draw()
{
	//背景
	Image::SetTransform(hBack_, backTr_);
	Image::Draw(hBack_);
}

//開放
void Back_Title::Release()
{
}