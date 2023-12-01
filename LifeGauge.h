#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class LifeGauge : public GameObject
{
private:
    int hPictGauge_;    //�摜�ԍ�(�Q�[�W�{��)
    int hPictFrame_;    //�摜�ԍ�(�Q�[�W�t���[��)

    float nowHp_;    //���̒l
    const float maxHp_ = 1.0f;  //�ő�l
    const float minHp_ = 0.0f;  //�ŏ��l
    float aniHp_;   //�\���p�̒l
    int ImageWidth;     //�Q�[�W�{�̉摜�̕�
    int ImageHeight;    //�Q�[�W�{�̉摜�̍���

    bool flag = true;
    float power = 0;
    float scalex = 1.3f;

    float MIN = 0.0f;
    float MAX = 1.0f;

public:

    //�R���X�g���N�^
    LifeGauge(GameObject* parent);

    //�f�X�g���N�^
    ~LifeGauge();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�Q�[�W�̈ʒu�ݒ�
    void SetPosition(float x, float y, float z);

    //�l�̉����Z
    void AddValue(float v);

    //�l�̃Z�b�g
    void SetValue(float v);

    //���݂�HP�擾
    float GetValue();
};