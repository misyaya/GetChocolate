#pragma once
#include "Engine/GameObject.h"

//���U���g�V�[�����Ǘ�����N���X
class ResultScene : public GameObject
{
	//�e��l
	int chocoPoint_;  //�`���R���[�g�l����
	int enemyPoint_;  //�G�l�~�[���j��
	int criteria_;    //�N���A�

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