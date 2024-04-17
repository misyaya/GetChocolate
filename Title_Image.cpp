#include "Title_Image.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"

//コンストラクタ
Title_Image::Title_Image(GameObject* parent)
	:GameObject(parent, "Title_Image"),
	hBack_(-1), hLogo_(-1), hKey_(-1), 
	keyAlpha_(0), keyShading_(0)
{
}

//デストラクタ
Title_Image::~Title_Image()
{
}

//初期化
void Title_Image::Initialize()
{
	//画像データのロード
	//背景
	hBack_ = Image::Load("Image/backGround.png");
	assert(hBack_ >= 0);

	//タイトルロゴ
	hLogo_ = Image::Load("Image/title_Logo.png");
	assert(hLogo_ >= 0);

	//キー操作誘導
	hKey_ = Image::Load("Image/pressSpace.png");
	assert(hKey_ >= 0);



	//画像情報
	//ロゴ
	trLogo_.position_.y += 0.5f;  //y座標

	//キー操作誘導
	trKey_.scale_ = XMFLOAT3(0.5f, 0.5f, 0.5f);   //拡大率
	trKey_.position_.y -= 0.5f;                   //y座標
}

//更新
void Title_Image::Update()
{
	//スペースキーが押されたらゲーム画面に移行
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MAINGAME);
	}



	//キー操作誘導の点滅
	if (keyAlpha_ >= 200)  //透明度が200以上になれば下げる
	{
		keyShading_ = -5;
	}
	else if (keyAlpha_ <= 0) //透明度が0以下になれば上げる
	{
		keyShading_ = 5;
	}

	//hKey_透明度の計算
	keyAlpha_ += keyShading_;

	//hKey_透明度をセット
	Image::SetAlpha(hKey_, keyAlpha_);
}

//描画
void Title_Image::Draw()
{
	//背景
	Image::SetTransform(hBack_, trBack_);
	Image::Draw(hBack_);

	//タイトルロゴ
	Image::SetTransform(hLogo_, trLogo_);
	Image::Draw(hLogo_);

	//キー操作誘導
	Image::SetTransform(hKey_, trKey_);
	Image::Draw(hKey_);
}

//開放
void Title_Image::Release()
{
}