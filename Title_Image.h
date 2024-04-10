#pragma once
#include "Engine/GameObject.h"

//�^�C�g���V�[���ɕ\������摜���Ǘ�����N���X
class Title_Image : public GameObject
{
    //�摜
    int hBack_;  //�w�i
    int hLogo_;  //�^�C�g�����S
    int hKey_;   //�L�[����U��



    //�摜���
    Transform trBack_;  //hBack_���
    Transform trLogo_;  //hLogo_���
    Transform trKey_;   //hKey_����U�����



    //�摜�����x�֘A
    //�L�[����U��
    int keyAlpha_;    //hKey_�����x
    int keyShading_;  //hKey_�����x�̉���

public:
    //�R���X�g���N�^
    Title_Image(GameObject* parent);

    //�f�X�g���N�^
    ~Title_Image();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};