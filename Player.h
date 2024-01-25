#pragma once
#include "Engine/GameObject.h"
#include "LifeGauge.h"
#include "Sword.h"
#include "Engine/Text.h"

//���������Ǘ�����N���X
class Player : public GameObject
{
private:
   int hModel_;    //���f���ԍ�4
   int hPictHp_;
   int hB_;
   int nowHp_;
   int maxHp_;

   int time_;

   Transform kari;
   Transform front;
   Transform hpTr_;
   
   Text* pText;

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

    void SetInvulnerable();

    void SetPlayerPos(XMFLOAT3 _position);

    //XMFLOAT3 GetPlayerPos();
};