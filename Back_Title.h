#pragma once
#include "Engine/GameObject.h"

//�^�C�g���w�i���Ǘ�����N���X
class Back_Title : public GameObject
{
    int hBack_;    //�w�i

    Transform backTr_;

public:
    //�R���X�g���N�^
    Back_Title(GameObject* parent);

    //�f�X�g���N�^
    ~Back_Title();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};