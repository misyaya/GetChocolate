#pragma once
#include "Engine/GameObject.h"
#include "Sword.h"
#include "Engine/Text.h"

//�v���C���[���Ǘ�����N���X
class Player : public GameObject
{
private:
    //���f��
   int hModel_;   

   //�l
   int hPictHp_;
   int hB_;
   int nowHp_;
   int maxHp_;
  
   int chocoPoint_; //�`���R���[�g�l����
   int enemyPoint_; //�G�l�~�[���j��

   Transform tentative;
   Transform front;
   Transform hpTr_;
   
   //HP�\��
   Text* pText;
   Text* pTextHp;

   //�`���R���[�g�l�����\��
   Text* pTextC;
   Text* pChoco;

   //�G�l�~�[���j��
   Text* pTextE;
   Text* pEnemy;

   int situation = 0;


   //���G����
   enum class InvincibilityState
   {
       Normal,
       Invincible
   };
   float invinTime;
   const float invinDuration = 5.0f * 60.0f;
   InvincibilityState invinState;
   float deltaTime;

   //�T�E���h
   int sWalk_; //����
   int sDamage_; //�_���[�W��
   int sInvin_; //���G���Ԓ��̐ړG
   int sChocoGet_; //�`���R���[�g�����



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