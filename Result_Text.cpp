#include "Result_Text.h"
#include "ValueManager.h"

//コンストラクタ
Result_Text::Result_Text(GameObject* parent)
    :GameObject(parent, "Result_Text"),
	enemyPoint_(0),chocoPoint_(0),
	pTextE(nullptr), pEnemy(nullptr), pTextC(nullptr), pChoco(nullptr)
{
}

//デストラクタ
Result_Text::~Result_Text()
{
}

//初期化
void Result_Text::Initialize()
{
	pTextE = new Text;
	pTextE->Initialize();

	pEnemy = new Text;
	pEnemy->Initialize();

	pTextC = new Text;
	pTextC->Initialize();

	pChoco = new Text;
	pChoco->Initialize();

	//値
	chocoPoint_ = ValueManager::GetInstance().GetPoints();
	enemyPoint_ = ValueManager::GetInstance().GetEnemyD();

}

//更新
void Result_Text::Update()
{
}

//描画
void Result_Text::Draw()
{
	//値表示
	pTextC->Draw(500, 500, "CH");
	pChoco->Draw(580, 500, chocoPoint_);
	pTextE->Draw(700, 500, "EN");
	pEnemy->Draw(780, 500, enemyPoint_);
}

//開放
void Result_Text::Release()
{
}