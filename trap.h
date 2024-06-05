#pragma once
#include "Engine/GameObject.h"

//㩂��Ǘ�����N���X
class Trap : public GameObject
{
    //���f��
    int hTrap_;

    //���f���̏��
    int state_;

    enum {
        WAIT = 0,
        DOWN,
        UP
    };

    float speed_;
    bool movingUp_;

public:
    //�R���X�g���N�^
    Trap(GameObject* parent);

    //�f�X�g���N�^
    ~Trap();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};