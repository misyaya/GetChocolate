#include "StartButton.h"
#include "Engine/Image.h"
#include "Engine/Direct3D.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
StartButton::StartButton(GameObject* parent)
    :GameObject(parent, "StartButton"), hButton_(-1)
{
}

//�f�X�g���N�^
StartButton::~StartButton()
{
}

//������
void StartButton::Initialize()
{
	//�{�^��
	hButton_ = Image::Load("TitleButton.png");
	assert(hButton_ >= 0);

	buttonTr_.scale_ = XMFLOAT3(0.5f, 0.5f, 0.5f);
	buttonTr_.position_.y -= 0.5f;
}

//�X�V
void StartButton::Update()
{
	//�X�y�[�X�L�[�������ꂽ��Q�[����ʂɈڍs
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MAINGAME);

	}

	//mouse = Input::GetMousePosition();

	//SetPosition(buttonTr_.position_.x, buttonTr_.position_.y);
	
}

//�`��
void StartButton::Draw()
{
	//if(MouseInArea(mouse))
	{
		//Image::SetAlpha(hButton_, 128);
		//�{�^��
		Image::SetTransform(hButton_, buttonTr_);
		Image::Draw(hButton_);
	}
	//else
	//{
	//	//�{�^��
	//	Image::SetTransform(hButton_, buttonTr_);
	//	Image::Draw(hButton_);
	//}

}

//�J��
void StartButton::Release()
{
}

void StartButton::Push(bool pushed)
{
	this->pushed = pushed;
}

bool StartButton::MouseInArea(XMFLOAT3 mousePos)
{
	
	if (abs(mousePos.x - center.x) > size.x / 2)
		return false;
	if (abs(mousePos.y - center.y) > size.y / 2)
		return false;
	return true;
}

void StartButton::SetPosition(int x, int y)
{
	buttonTr_.position_.x = (float)(x - Direct3D::screenWidth_ / 2) / Direct3D::screenWidth_;
	buttonTr_.position_.y = -(float)(y - Direct3D::screenHeight_ / 2) / (Direct3D::screenHeight_ / 2);
	center = XMFLOAT3(x, y, 0);
}