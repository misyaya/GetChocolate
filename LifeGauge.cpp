#include "LifeGauge.h"
#include 

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
}

//更新
void LifeGauge::Update()
{
}

//描画
void LifeGauge::Draw()
{
}

//開放
void LifeGauge::Release()
{
}

void LifeGauge::SetPosition(float x, float y, float z)
{
}

void LifeGauge::AddValue(float v)
{
}

void LifeGauge::SetValue(float v)
{
}

float LifeGauge::GetValue()
{
    return 0.0f;
}
