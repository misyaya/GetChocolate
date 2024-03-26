#include "PressSpace.h"
#include "Engine/Image.h"
#include "Engine/Direct3D.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
PressSpace::PressSpace(GameObject* parent)
	:GameObject(parent, "PressSpace"), hButton_(-1), alpha_(0), shading_(0)
{
}

//�f�X�g���N�^
PressSpace::~PressSpace()
{
}

//������
void PressSpace::Initialize()
{
	//�{�^��
	hButton_ = Image::Load("pressSpace.png");
	assert(hButton_ >= 0);

	buttonTr_.scale_ = XMFLOAT3(0.5f, 0.5f, 0.5f);
	buttonTr_.position_.y -= 0.5f;
}

//�X�V
void PressSpace::Update()
{
	//�X�y�[�X�L�[�������ꂽ��^�C�g����ʂɈڍs
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

//�`��
void PressSpace::Draw()
{
	Image::SetTransform(hButton_, buttonTr_);
	Image::Draw(hButton_);

}

//�J��
void PressSpace::Release()
{
}

void PressSpace::Push(bool pushed)
{
	this->pushed = pushed;
}

bool PressSpace::MouseInArea(XMFLOAT3 mousePos)
{
	if (abs(mousePos.x - center.x) > size.x / 2)
		return false;
	if (abs(mousePos.y - center.y) > size.y / 2)
		return false;
	return true;
}

void PressSpace::SetPosition(int x, int y)
{
	buttonTr_.position_.x = (float)(x - Direct3D::screenWidth_ / 2) / Direct3D::screenWidth_;
	buttonTr_.position_.y = -(float)(y - Direct3D::screenHeight_ / 2) / (Direct3D::screenHeight_ / 2);
	center = XMFLOAT3(x, y, 0);
}