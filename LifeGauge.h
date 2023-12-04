#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class LifeGauge : public GameObject
{
private:
    int hPictGauge_;    //�摜�ԍ�(�Q�[�W�{��)
    int hPictFrame_;    //�摜�ԍ�(�Q�[�W�t���[��)

    float nowHp_;    //���̒l
    float maxHp_;  //�ő�l
    const float minHp_ = 0.0f;  //�ŏ��l
    float aniHp_;   //�\���p�̒l
    int ImageWidth;     //�Q�[�W�{�̉摜�̕�
    int ImageHeight;    //�Q�[�W�{�̉摜�̍���

    bool flag = true;
    float power = 0;


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

    //HP�ݒ�
    void SetHp(float _nowHp, int _maxHp);

    //�Q�[�W�̈ʒu�ݒ�
    void SetPosition(float x, float y, float z);

    //�Q�[�W�̌����ݒ�
    void SetRotate(float x, float y, float z);

    //�l�̉����Z
    void AddValue(float v);

    //�l�̃Z�b�g
    void SetValue(float v);

    //���݂�HP�擾
    float GetValue();
};