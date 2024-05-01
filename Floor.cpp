#include "Floor.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"

//�R���X�g���N�^
Floor::Floor(GameObject* parent)
    :GameObject(parent, "Floor"),
    hModel_{-1,-1}, table_(nullptr), width_(0), height_(0)
{
    CsvReader csv;
    csv.Load("map.csv");

    width_ = csv.GetWidth();
    height_ = csv.GetHeight();


    //�z����
    table_ = new int* [width_];

    for (int x = 0; x < width_; x++)
    {
        table_[x] = new int[height_];
    }

    //�i�[
    for (int x = 0; x < width_; x++)
    {
        for (int z = 0; z < height_; z++)
        {
            table_[x][height_ - 1 - z] = csv.GetValue(x, z);
        }
    }

}

//�f�X�g���N�^
Floor::~Floor()
{
}

//������
void Floor::Initialize()
{
    const char* fileName[] = { "Fbx/Grass.fbx" , "Fbx/Soil.fbx" , "Fbx/GrassBox.fbx" , };


    //���f���f�[�^�̃��[�h
    for(int i = 0; i < TYPE_MAX; i++)
    {
        hModel_[i] = Model::Load(fileName[i]);
        assert(hModel_[i] >= 0);
    }

    hTree_ = Model::Load("Fbx/tree.fbx");
    assert(hTree_ >= 0);
}

//�X�V
void Floor::Update()
{
}

//�`��
void Floor::Draw()
{
    Transform blockTrans;

    for (int x = 0; x < width_; x++)
    {
        for (int z = 0; z < height_; z++)
        {
            blockTrans.position_.x = x;
            blockTrans.position_.z = z;

            int type = table_[x][z];
            Model::SetTransform(hModel_[type], blockTrans);
            Model::Draw(hModel_[type]);
        }
    }
   
    tree_.position_ = XMFLOAT3(3.0f, 0.0f, 20.0f);
    Model::SetTransform(hTree_, tree_);
    Model::Draw(hTree_);
}

//�J��
void Floor::Release()
{
    for (int x = 0; x < width_; x++)
    {
        delete[] table_[x];
    }

    delete[] table_;
}

bool Floor::IsWall(int x, int z)
{
    if (table_[x][z] == TYPE_GRASSBOX)
    {
        return true;
    }
    else
    {
        return false;
    }
}
