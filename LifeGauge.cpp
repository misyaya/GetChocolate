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
    //�Q�[�W�{�̉摜�̃��[�h
    hPictGauge_ = Image::Load("LifeGauge.png");
    assert(hPictGauge_ >= 0);

    //�Q�[�W�t���[���摜�̃��[�h
    hPictFrame_ = Image::Load("LifeGauge_Frame.png");
    assert(hPictFrame_ >= 0);

    //�Q�[�W�{�̉摜�̃T�C�Y
    ImageWidth = Image::GetWidth(hPictGauge_);
    ImageHeight = Image::GetHeight(hPictGauge_);
}

//�X�V
void LifeGauge::Update()
{
}

//�`��
void LifeGauge::Draw()
{
    //���@�@=�@�@���S        -      ���S       *   ����HP
    int left = ImageWidth / 2 - ImageWidth / 2 * nowHp_;

    //��    =    �摜��    *   ����HP
    int width = ImageWidth * nowHp_;

    // �Q�[�W�{�̂̐؂蔲�������A�`��
    Image::SetRect(hPictGauge_, left, 0, width, ImageHeight);
    Image::SetTransform(hPictGauge_, transform_);
    Image::Draw(hPictGauge_);
    
    // �Q�[�W�t���[���`��
    Image::SetTransform(hPictFrame_, transform_);
    Image::Draw(hPictFrame_);
}

//�J��
void LifeGauge::Release()
{
}

//�Q�[�W�̈ʒu�ݒ�
void LifeGauge::SetPosition(float x, float y, float z)
{
    transform_.position_.x = x;
    transform_.position_.y = y;
    transform_.position_.z = z;
}

//�l�̉����Z
void LifeGauge::AddValue(float v)
{
    nowHp_ += v;

    if (nowHp_ < minHp_)
        nowHp_ = minHp_;
    else if (nowHp_ > maxHp_)
        nowHp_ = maxHp_;
}

//�l�̃Z�b�g
void LifeGauge::SetValue(float v)
{
    assert(v >= 0.0f && v <= 1.0f);
    
    nowHp_ = v;
    if (nowHp_ < minHp_)
        nowHp_ = minHp_;
    else if (nowHp_ > maxHp_)
        nowHp_ = maxHp_;
}

//���݂�HP�擾
float LifeGauge::GetValue()
{
    return nowHp_;
}
