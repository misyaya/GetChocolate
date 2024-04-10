#pragma once
#include "Engine/GameObject.h"

//�`���R���[�g���Ǘ�����N���X
class Chocolate : public GameObject
{
    //���f��
    int hChoco_;

    //�G�t�F�N�g
    int hEmit_;

public:
    //�R���X�g���N�^
    Chocolate(GameObject* parent);

    //�f�X�g���N�^
    ~Chocolate();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject* pTarget) override;
};