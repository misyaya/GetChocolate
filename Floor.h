#pragma once
#include "Engine/GameObject.h"

enum
{
    TYPE_GRASS,
    TYPE_SOIL,
    TYPE_GRASSBOX,
    TYPE_MAX,
};


//�X�e�[�W�����Ǘ�����N���X
class Floor : public GameObject
{
    //���f��
    int hModel_[TYPE_MAX];    //���f���ԍ�

    int** table_;

    int width_, height_;

public:
    //�R���X�g���N�^
    Floor(GameObject* parent);

    //�f�X�g���N�^
    ~Floor();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    /// <summary>
    /// �w�肵���ʒu���ʂ�邩�ʂ�Ȃ���
    /// </summary>
    /// <param name="x"></param>
    /// <param name="z"></param>
    /// <returns>�ʂ�Ȃ���true/�ʂ��=false</returns>
    bool IsWall(int x, int z);
};