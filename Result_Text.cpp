#include "Result_Text.h"
#include "ValueManager.h"

//�R���X�g���N�^
Result_Text::Result_Text(GameObject* parent)
    :GameObject(parent, "Result_Text"),
	enemyPoint_(0),chocoPoint_(0),
	pTextE(nullptr), pEnemy(nullptr), pTextC(nullptr), pChoco(nullptr)
{
}

//�f�X�g���N�^
Result_Text::~Result_Text()
{
}

//������
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

	//�l
	chocoPoint_ = ValueManager::GetInstance().GetPoints();
	enemyPoint_ = ValueManager::GetInstance().GetEnemyD();

}

//�X�V
void Result_Text::Update()
{
}

//�`��
void Result_Text::Draw()
{
	//�l�\��
	pTextC->Draw(500, 500, "CH");
	pChoco->Draw(580, 500, chocoPoint_);
	pTextE->Draw(700, 500, "EN");
	pEnemy->Draw(780, 500, enemyPoint_);
}

//�J��
void Result_Text::Release()
{
}