#include "MissionDisplay.h"
#include "MissionManager.h"

//コンストラクタ
MissionDisplay::MissionDisplay(GameObject* parent)
    :GameObject(parent, "MissionDisplay")
{
}

//デストラクタ
MissionDisplay::~MissionDisplay()
{
}

//初期化
void MissionDisplay::Initialize()
{
    MissionManager manager;
    manager.AddMission("敵を３体倒す");
    manager.AddMission("アイテムを３個獲得する");
    manager.AddMission("ゴールする");

    manager.StartMission("敵を３体倒す");
}

//更新
void MissionDisplay::Update()
{
}

//描画
void MissionDisplay::Draw()
{
}

//開放
void MissionDisplay::Release()
{
}