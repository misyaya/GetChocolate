#pragma once
#include "Engine/GameObject.h"

//GameClear���Ǘ�����N���X
class GameClear : public GameObject
{
    //�摜
    int hGameClear_;  //GameClear!!�̕���
    int hPerfect_;    //Perfect!�̕���



    //�T�E���h
    int sGameClear_;  //���̃N���X���Ăт����ꂽ���ɖ�



    //�摜���
    Transform trClear_;    //hGameClear_���
    Transform trPerfect_;  //hPerfect_���



    //�e��l
    int chocoPoint_;  //�`���R���[�g�l����
    int enemyPoint_;  //�G�l�~�[���j��

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