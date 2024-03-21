#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"


//���U���g�V�[�����Ǘ�����N���X
class ResultScene : public GameObject
{
	Text* pTextE;
	Text* pEnemy; //Enemy��|������

	Text* pTextC;
	Text* pChoco;

	int chocoPoint_;
	int enemyPoint_;

	//�摜�f�[�^
	int hBack_;    
	int hGameClear_;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	ResultScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};