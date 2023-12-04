#pragma once
#include "Engine/GameObject.h"
#include  "LifeGauge.h"

//���������Ǘ�����N���X
class Player : public GameObject
{
    int hModel_;    //���f���ԍ�
    Transform kari;
    Transform front;

    int nowHp_;
   // LifeGauge* pLifeGauge = (LifeGauge*)FindObject("Gauge");
public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

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
};