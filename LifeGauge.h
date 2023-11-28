#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class LifeGauge : public GameObject
{
private:
    int hPictGauge_;    //�摜�ԍ�(�Q�[�W�̒��g)
    int hPictFrame_;    //�摜�ԍ�(�Q�[�W�̊O�g)

    float nowHp_;       //���̒l
    const float maxHp_ = 1.0f; //�ő�l
    float animHp_; //�\���p�̒l
    int ImageWidth;   //�Q�[�W�摜�̕�
    int ImageHeight;  //�Q�[�W�摜�̍���


    bool flag = true;
    float power = 0;
    float scalex = 1.3f;

public:
    static constexpr float MIN = 0.0f;
    static constexpr float MAX = 1.0f;

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

    void SetPosition(float x, float y, float z);

    void AddValue(float v);

    void SetValue(float v);

    float GetValue();
};