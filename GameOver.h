#pragma once
#include "Engine/GameObject.h"

//GameOver...�̉摜���Ǘ�����N���X
class GameOver : public GameObject
{
    //�摜�f�[�^
    int hGameOver_;

public:
    //�R���X�g���N�^
    GameOver(GameObject* parent);

    //�f�X�g���N�^
    ~GameOver();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};