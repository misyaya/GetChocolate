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
    hPictGauge_ = Image::Load("LifeGauge.png");
    assert(hPictGauge_ >= 0);

    //ゲージフレーム画像のロード
    hPictFrame_ = Image::Load("LifeGauge_Frame.png");
    assert(hPictFrame_ >= 0);

    //ゲージ本体画像のサイズ
    ImageWidth = Image::GetWidth(hPictGauge_);
    ImageHeight = Image::GetHeight(hPictGauge_);
}

//更新
void LifeGauge::Update()
{
}

//描画
void LifeGauge::Draw()
{
    //左　　=　　中心        -      中心       *   今のHP
    int left = ImageWidth / 2 - ImageWidth / 2 * nowHp_;

    //幅    =    画像幅    *   今のHP
    int width = ImageWidth * nowHp_;

    // ゲージ本体の切り抜き調整、描画
    Image::SetRect(hPictGauge_, left, 0, width, ImageHeight);
    Image::SetTransform(hPictGauge_, transform_);
    Image::Draw(hPictGauge_);
    
    // ゲージフレーム描画
    Image::SetTransform(hPictFrame_, transform_);
    Image::Draw(hPictFrame_);
}

//開放
void LifeGauge::Release()
{
}

//ゲージの位置設定
void LifeGauge::SetPosition(float x, float y, float z)
{
    transform_.position_.x = x;
    transform_.position_.y = y;
    transform_.position_.z = z;
}

//値の加減算
void LifeGauge::AddValue(float v)
{
    nowHp_ += v;

    if (nowHp_ < minHp_)
        nowHp_ = minHp_;
    else if (nowHp_ > maxHp_)
        nowHp_ = maxHp_;
}

//値のセット
void LifeGauge::SetValue(float v)
{
    assert(v >= 0.0f && v <= 1.0f);
    
    nowHp_ = v;
    if (nowHp_ < minHp_)
        nowHp_ = minHp_;
    else if (nowHp_ > maxHp_)
        nowHp_ = maxHp_;
}

//現在のHP取得
float LifeGauge::GetValue()
{
    return nowHp_;
}
