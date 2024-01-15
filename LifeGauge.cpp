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
    hPictHeart_ = Image::Load("Hpfive.png");
    assert(hPictHeart_ >= 0);

    //�Q�[�W�{�̉摜�̃T�C�Y
    ImageWidth = Image::GetWidth(hPictHeart_);
    ImageHeight = Image::GetHeight(hPictHeart_);

    SetPosition(-0.6f, 0.8f, 0.0f);
}

//�X�V
void LifeGauge::Update()
{
}

//�`��
void LifeGauge::Draw()
{
    //���@�@ =�@�@���S         -     ���S        *   ����HP
    int left = ImageWidth / 2 - ImageWidth / 2 * nowHp_;

    //��      =    �摜��  *   ����HP
    int width = ImageWidth - nowHp_;


    // �Q�[�W�{�̂̐؂蔲�������A�`��
    Image::SetRect(hPictHeart_, 0, 0, 400, ImageHeight);
    Image::SetTransform(hPictHeart_, transform_);
    Image::Draw(hPictHeart_);
}

//�J��
void LifeGauge::Release()
{
}

void LifeGauge::SetHp(float _nowHp, int _maxHp)
{
    nowHp_ = _nowHp;
    maxHp_ = _maxHp;
}

//�Q�[�W�̈ʒu�ݒ�
void LifeGauge::SetPosition(float x, float y, float z)
{
    transform_.position_.x = x;
    transform_.position_.y = y;
    transform_.position_.z = z;
}

void LifeGauge::SetRotate(float x, float y, float z)
{
    transform_.rotate_.x = x;
    transform_.rotate_.y = y;
    transform_.rotate_.z = z;
}

////�l�̉����Z
//void LifeGauge::AddValue(float v)
//{
//    nowHp_ += v;
//
//    if (nowHp_ < minHp_)
//        nowHp_ = minHp_;
//    else if (nowHp_ > maxHp_)
//        nowHp_ = maxHp_;
//}
//
////�l�̃Z�b�g
//void LifeGauge::SetValue(float v)
//{
//    assert(v >= 0.0f && v <= 1.0f);
//    
//    nowHp_ = v;
//    if (nowHp_ < minHp_)
//        nowHp_ = minHp_;
//    else if (nowHp_ > maxHp_)
//        nowHp_ = maxHp_;
//}
//
////���݂�HP�擾
//float LifeGauge::GetValue()
//{
//    return nowHp_;
//}
