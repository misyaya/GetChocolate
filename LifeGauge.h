#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class LifeGauge : public GameObject
{
private:
    int hPictGauge_;    //�摜�ԍ�(�Q�[�W�̒��g)
    int hPictFrame_;    //�摜�ԍ�(�Q�[�W�̊O�g)

    float nowHp;    //���̒l
    const float maxHp_ = 1.0f;  //�ő�l
    float aniHp_;   //�\���p�̒l
    int ImageWidth;     //�Q�[�W�摜�̕�
    int ImageHeight;    //�Q�[�W�摜�̍���

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

    //�ʒu
    void SetPosition(float x, float y, float z);

    //�l�������Z����
    void AddValue(float v);

    //
    void SetValue(float v);

    float GetValue();
};