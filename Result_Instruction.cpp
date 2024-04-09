#include "Result_Instruction.h"
#include "Engine/Image.h"
#include "Engine/Direct3D.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
Result_Instruction::Result_Instruction(GameObject* parent)
	:GameObject(parent, "Result_Instruction"), hButton_(-1), alpha_(0), shading_(0)
{
}

//デストラクタ
Result_Instruction::~Result_Instruction()
{
}

//初期化
void Result_Instruction::Initialize()
{
	//ボタン
	hButton_ = Image::Load("Image/pressSpace.png");
	assert(hButton_ >= 0);

	buttonTr_.scale_ = XMFLOAT3(0.5f, 0.5f, 0.5f);
	buttonTr_.position_.y -= 0.5f;
}

//更新
void Result_Instruction::Update()
{
	//スペースキーが押されたらタイトル画面に移行
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);

	}


	if (alpha_ >= 200) {
		shading_ = -1;
	}
	else if (alpha_ <= 0) {
		shading_ = 1;
	}

	alpha_ += 5 * shading_;


	Image::SetAlpha(hButton_, alpha_);

}

//描画
void Result_Instruction::Draw()
{
	Image::SetTransform(hButton_, buttonTr_);
	Image::Draw(hButton_);

}

//開放
void Result_Instruction::Release()
{
}

void Result_Instruction::Push(bool pushed)
{
	this->pushed = pushed;
}

bool Result_Instruction::MouseInArea(XMFLOAT3 mousePos)
{
	if (abs(mousePos.x - center.x) > size.x / 2)
		return false;
	if (abs(mousePos.y - center.y) > size.y / 2)
		return false;
	return true;
}

void Result_Instruction::SetPosition(int x, int y)
{
	buttonTr_.position_.x = (float)(x - Direct3D::screenWidth_ / 2) / Direct3D::screenWidth_;
	buttonTr_.position_.y = -(float)(y - Direct3D::screenHeight_ / 2) / (Direct3D::screenHeight_ / 2);
	center = XMFLOAT3(x, y, 0);
}