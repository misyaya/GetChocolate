#include "LifeGauge.h"
#include "Engine/Image.h"

//�R���X�g���N�^
LifeGauge::LifeGauge(GameObject* parent)
    :GameObject(parent, "LifeGauge")
{
}

//�f�X�g���N�^
LifeGauge::~LifeGauge()
{
}

//������
void LifeGauge::Initialize()
{
    //�摜�f�[�^�̃��[�h
    hPictGauge_ = Image::Load("LifeGauge.png");
    assert(hPictGauge_ >= 0);

    //�摜�f�[�^�̃��[�h
    hPictFrame_ = Image::Load("LifeGauge_Frame.png");
    assert(hPictFrame_ >= 0);

    ImageWidth = Image::GetWidth(hPictGauge_);
    ImageHeight = Image::GetHeight(hPictGauge_);

    SetPosition(-0.9,0.8,0);

    /*transform_.position_.x = -0.9f;
    transform_.position_.y = -0.5f;
    transform_.position_.z = 10.0f;*/
}

//�X�V
void LifeGauge::Update()
{
}

//�`��
void LifeGauge::Draw()
{
    int left = ImageWidth / 2 - ImageWidth / 2 * nowHp_;
    int width = ImageWidth * nowHp_;
    Image::SetRect(hPictGauge_, left, 0, width, ImageHeight);
    Image::SetTransform(hPictGauge_, transform_);
    Image::Draw(hPictGauge_);


    Image::SetTransform(hPictFrame_, transform_);
    Image::Draw(hPictFrame_);
}

//�J��
void LifeGauge::Release()
{
}
void LifeGauge::SetPosition(float x, float y, float z)
{
    transform_.position_.x = x;
    transform_.position_.y = y;
    transform_.position_.z = z;
}

void LifeGauge::AddValue(float v)
{
    nowHp_ += v;
    if (nowHp_ < 0.0f)
        nowHp_ = 0.0f;
    else if (nowHp_ > maxHp_)
        nowHp_ = maxHp_;
}

void LifeGauge::SetValue(float v)
{
    assert(v >= 0.0f && v <= 1.0f);

    nowHp_ = v;
    if (nowHp_ < 0.0f)
        nowHp_ = 0.0f;
    else if (nowHp_ > maxHp_)
        nowHp_ = maxHp_;
}

float LifeGauge::GetValue()
{
    return nowHp_;
}
