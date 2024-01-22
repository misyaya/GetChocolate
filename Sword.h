#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Sword : public GameObject
{
    int sword_;
public:
    //�R���X�g���N�^
    Sword(GameObject* parent);

    //�f�X�g���N�^
    ~Sword();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����蔻��
    void OnCollision(GameObject* pTarget);

    //
    void SetSwordTr(XMFLOAT3 _transform);
};