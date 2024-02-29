#pragma once
#include "Engine/GameObject.h"
#include "LifeGauge.h"
#include "Sword.h"
#include "Engine/Text.h"

//�v���C���[���Ǘ�����N���X
class Player : public GameObject
{
private:
   int hModel_;    //���f���ԍ�4
   int hPictHp_;
   int hB_;
   int nowHp_;
   int maxHp_;

   Transform kari;
   Transform front;
   Transform hpTr_;
   
   Text* pText;
   Text* pTextHp;

   int situation = 0;


   enum class InvincibilityState
   {
       Normal,
       Invincible
   };
    
   float invinTime;
   const float invinDuration = 5.0f*60.0f;
   InvincibilityState invinState;
   float deltaTime;

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

    //���G����
    void SetInvulnerable();

    //Player�ʒu�̐ݒ�
    void SetPlayerPos(XMFLOAT3 _position);

    //Player�ʒu�̎擾
    XMFLOAT3 GetPlayerPos();

    //�J����
    void UpdateCamera();

    //���ɔ��
    void MoveBackward(float _distance);
};