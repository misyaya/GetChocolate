#include "Result_Image.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
Result_Image::Result_Image(GameObject* parent)
	:GameObject(parent, "Result_Image"),
	hBack_(-1), hBackLittle_(-1), hResultName_(-1), hKey_(-1), 
	keyAlpha_(0), keyShading_(0)
{
}

//デストラクタ
Result_Image::~Result_Image()
{
}

//初期化
void Result_Image::Initialize()
{
	//画像データのロード
	//背景
	hBack_ = Image::Load("Image/BackGround.png");
	assert(hBack_ >= 0);

	//背景小
	hBackLittle_ = Image::Load("Image/result_BackLittle.png");
	assert(hBackLittle_ >= 0);

	//Result文字
	hResultName_ = Image::Load("Image/resultName.png");
	assert(hResultName_ >= 0);

	//キー操作誘導
	hKey_ = Image::Load("Image/pressSpace.png");
	assert(hKey_ >= 0);



	//画像情報
	//背景(小)
	trBackL_.position_.y = -0.4f;                  //y座標
	trBackL_.scale_ = XMFLOAT3(0.9f, 0.2f, 1.0f);  //拡大率

	//Result文字
	trResultN_.position_.y = 0.8f;                   //y座標
	trResultN_.scale_ = XMFLOAT3(0.4f, 0.4f, 1.0f);  //拡大率

	//キー操作誘導
	trKey_.scale_ = XMFLOAT3(0.5f, 0.5f, 0.5f);   //拡大率
	trKey_.position_.y -= 0.5f;                   //y座標
}

//更新
void Result_Image::Update()
{
	//スペースキーが押されたらゲーム画面に移行
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
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

	//透明度の計算
	keyAlpha_ += keyShading_;

	//透明度をセット
	Image::SetAlpha(hKey_, keyAlpha_);
}

//描画
void Result_Image::Draw()
{
	//背景
	Image::SetAlpha(hBack_, 128);
	Image::SetTransform(hBack_, trBack_);
	Image::Draw(hBack_);

	//背景(小)
	Image::SetAlpha(hBackLittle_, 100);
	Image::SetTransform(hBackLittle_, trBackL_);
	Image::Draw(hBackLittle_);

	//Result文字
	Image::SetTransform(hResultName_, trResultN_);
	Image::Draw(hResultName_);

	//キー操作誘導
	Image::SetTransform(hKey_, trKey_);
	Image::Draw(hKey_);
}

//開放
void Result_Image::Release()
{
}