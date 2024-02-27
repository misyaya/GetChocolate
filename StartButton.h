#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class StartButton : public GameObject
{
    int hButton_;  //�{�^��
    bool pushed; // ������Ă��邩

    XMFLOAT3 center; //�{�^���̒��S���W(��ʍ��W)
    XMFLOAT3 size; //�{�^���̉摜�T�C�Y

    Transform buttonTr_;

    XMFLOAT3 mouse;

public:
    //�R���X�g���N�^
    StartButton(GameObject* parent);

    //�f�X�g���N�^
    ~StartButton();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�{�^�������������A�����ĂȂ���
    void Push(bool pushed);

    //�}�E�X�{�^�����ɓ����Ă��邩
    bool MouseInArea(XMFLOAT3 mousePos);

    void SetPosition(int x, int y);
};