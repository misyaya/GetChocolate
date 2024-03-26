#pragma once
#include "Engine/GameObject.h"

//�X�^�[�g�{�^�����Ǘ�����N���X
class PressSpace : public GameObject
{
    int hButton_;  //�{�^��
    bool pushed; // ������Ă��邩

    XMFLOAT3 center; //�{�^���̒��S���W(��ʍ��W)
    XMFLOAT3 size; //�{�^���̉摜�T�C�Y

    Transform buttonTr_;
    int alpha_;
    int shading_;

    XMFLOAT3 mouse;

public:
    //�R���X�g���N�^
    PressSpace(GameObject* parent);

    //�f�X�g���N�^
    ~PressSpace();

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