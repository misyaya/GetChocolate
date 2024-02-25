#pragma once
#include "Engine/GameObject.h"
#include <string>

using std::string;

//�~�b�V�������Ǘ�����N���X
class Mission : public GameObject
{
    struct mission {
        int num;
        string name;
        bool flag;
    };

    int minum_;

public:
    //�R���X�g���N�^
    Mission(GameObject* parent);

    //�f�X�g���N�^
    ~Mission();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};