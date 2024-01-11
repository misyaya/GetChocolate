#pragma once
#include "Engine/GameObject.h"
#include  "LifeGauge.h"

//���������Ǘ�����N���X
class Player : public GameObject
{
    int hModel_;    //���f���ԍ�4
    int hPictHp_;
    Transform kari;
    Transform front;
    Transform hpTr_;
   
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

    void SetPlayrPos(XMFLOAT3 _position);

    XMFLOAT3 GetPlayerPos();
};