#include "Chocolate.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"
#include "Engine/VFX.h"
#include "ValueManager.h"

//�R���X�g���N�^
Chocolate::Chocolate(GameObject* parent)
    :GameObject(parent, "Chocolate"), hChoco_(-1)
{
}

//�f�X�g���N�^
Chocolate::~Chocolate()
{
    VFX::End(hEmit_);
}

//������
void Chocolate::Initialize()
{
    //���f���f�[�^�̃��[�h
    hChoco_ = Model::Load("Fbx/present.fbx");
    assert(hChoco_ >= 0);

    transform_.position_.x = (float)(rand() % 20 + 10);
    transform_.position_.y = 1.0f;
    transform_.position_.z = (float)(rand() % 55 + 3);

    transform_.scale_ = XMFLOAT3(0.1f, 0.1f, 0.1f);

    transform_.rotate_.x = 90.0f;

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(2.0f, 2.0f, 2.0f));
    AddCollider(collision);

    EmitterData  data;
    data.textureFileName = "circle_Y.png";
    data.position = transform_.position_;
 
    data.delay = 5;
    data.lifeTime = 150;
    data.accel = 0.95;
    data.size = XMFLOAT2(2, 2);
    data.sizeRnd = XMFLOAT2(0.4, 0.4);
    data.scale = XMFLOAT2(1.01f, 1.01f);
    data.color.w = 0.2f; //�s�����x
    data.deltaColor.w = -0.002;
    data.position.y = -2.0f;
    data.rotateRnd.z = 180; //-180�`180 
    data.spin.z = 0.2f;


    hEmit_ = VFX::Start(data);	//�G�~�b�^�[��ݒu
  
}

//�X�V
void Chocolate::Update()
{
    transform_.rotate_.y += 1.0f;
}

//�`��
void Chocolate::Draw()
{
    Model::SetTransform(hChoco_, transform_);
    Model::Draw(hChoco_);
}

//�J��
void Chocolate::Release()
{
}

//�����ɓ�������
void Chocolate::OnCollision(GameObject* pTarget)
{
    //�v���C���[�ɓ��������Ƃ�
    if (pTarget->GetObjectName() == "Player")
    {
        ValueManager::GetInstance().AddPoints(1);
        VFX::End(hEmit_);
        KillMe();
    }
}