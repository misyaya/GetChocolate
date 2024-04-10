#pragma once
#include "Engine/GameObject.h"

//���U���g�V�[���̉摜���Ǘ�����N���X(GameClear��GameOver�͕ʃN���X�Ǘ�)
class Result_Image : public GameObject
{
    //�摜
    int hBack_;        //�w�i
    int hBackLittle_;  //�w�i(��)
    int hResultName_;  //RESULT!�Ə����Ă���摜
    int hKey_;         //�L�[����U��

    //�摜���
    Transform trBack_;     //hBack_���
    Transform trBackL_;    //hBackLittle_���
    Transform trResultN_;  //hResultName_���
    Transform trKey_;      //hKey_���

    //�摜�����x�֘A
    //�L�[����U��
    int keyAlpha_;    //hKey_�����x
    int keyShading_;  //hKey_�����x�̉���

public:
    //�R���X�g���N�^
    Result_Image(GameObject* parent);

    //�f�X�g���N�^
    ~Result_Image();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};