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

	//�T�E���h
	int sGameClear_;
	int sGameOver_;

	//�摜�f�[�^
	int hBack_;    
	int hBackSmall_;
	int hResultName_;
	int hPerfect_;
	int hGameClear_;

	//�摜�̈ʒu���
	Transform trBackS_;
	Transform trResultN_;
	Transform trPerfect_;

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