#pragma once
#include "Engine/GameObject.h"

//GameClear���Ǘ�����N���X
class GameClear : public GameObject
{
    //�摜
    int hGameClear_;

    //�T�E���h
    int sGameClear_;

public:
    //�R���X�g���N�^
    GameClear(GameObject* parent);

    //�f�X�g���N�^
    ~GameClear();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};