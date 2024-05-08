#include "Tree.h"
#include "Engine/Model.h"

//コンストラクタ
Tree::Tree(GameObject* parent)
    :GameObject(parent, "Tree"), hTree_(-1)
{
}

//デストラクタ
Tree::~Tree()
{
}

//初期化
void Tree::Initialize()
{
    //モデルデータのロード
    hTree_ = Model::Load("Fbx/tree.fbx");
    assert(hTree_ >= 0);
}

//更新
void Tree::Update()
{
}

//描画
void Tree::Draw()
{
    transform_.position_ = XMFLOAT3(10.0f, 0.0f, 10.0f);
    Model::SetTransform(hTree_, transform_);
    Model::Draw(hTree_);
}

//開放
void Tree::Release()
{
}