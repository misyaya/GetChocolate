#include "LifeGauge.h"
#include "Engine/Image.h"

//コンストラクタ
LifeGauge::LifeGauge(GameObject* parent)
    :GameObject(parent, "LifeGauge")
{
}

//デストラクタ
LifeGauge::~LifeGauge()
{
}

//初期化
void LifeGauge::Initialize()
{
    //ゲージ本体画像のロード
    hPictHeart_ = Image::Load("Hpfive.png");
    assert(hPictHeart_ >= 0);

    //ゲージ本体画像のサイズ
    ImageWidth = Image::GetWidth(hPictHeart_);
    ImageHeight = Image::GetHeight(hPictHeart_);

    SetPosition(-0.6f, 0.8f, 0.0f);
}

//更新
void LifeGauge::Update()
{
}

//描画
void LifeGauge::Draw()
{
    //左　　 =　　中心         -     中心        *   今のHP
    int left = ImageWidth / 2 - ImageWidth / 2 * nowHp_;

    //幅      =    画像幅  *   今のHP
    int width = ImageWidth - nowHp_;


    // ゲージ本体の切り抜き調整、描画
    Image::SetRect(hPictHeart_, 0, 0, 400, ImageHeight);
    Image::SetTransform(hPictHeart_, transform_);
    Image::Draw(hPictHeart_);
}

//開放
void LifeGauge::Release()
{
}

void LifeGauge::SetHp(float _nowHp, int _maxHp)
{
    nowHp_ = _nowHp;
    maxHp_ = _maxHp;
}

//ゲージの位置設定
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

////値の加減算
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
////値のセット
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
////現在のHP取得
//float LifeGauge::GetValue()
//{
//    return nowHp_;
//}
