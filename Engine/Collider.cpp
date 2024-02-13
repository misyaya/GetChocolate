#include "BoxCollider.h"
#include "SphereCollider.h"
#include "GameObject.h"
#include "Model.h"
#include "Transform.h"

//コンストラクタ
Collider::Collider():
	pGameObject_(nullptr)
{
}

//デストラクタ
Collider::~Collider()
{
}

//箱型同士の衝突判定
//引数：boxA	１つ目の箱型判定
//引数：boxB	２つ目の箱型判定
//戻値：接触していればtrue
bool Collider::IsHitBoxVsBox(BoxCollider* boxA, BoxCollider* boxB)
{
	XMFLOAT3 centerA = boxA->center_;
	XMFLOAT3 rotateA = boxA->rotate_;

	XMFLOAT3 centerB = boxB->center_;
	XMFLOAT3 rotateB = boxB->rotate_;

	ColliderRotate(centerA, rotateA);
	ColliderRotate(centerB, rotateB);
	
	XMFLOAT3 boxPosA = Transform::Float3Add(boxA->pGameObject_->GetWorldPosition(), boxA->center_);
	XMFLOAT3 boxPosB = Transform::Float3Add(boxB->pGameObject_->GetWorldPosition(), boxB->center_);


	if ((boxPosA.x + boxA->size_.x / 2) > (boxPosB.x - boxB->size_.x / 2) &&
		(boxPosA.x - boxA->size_.x / 2) < (boxPosB.x + boxB->size_.x / 2) &&
		(boxPosA.y + boxA->size_.y / 2) > (boxPosB.y - boxB->size_.y / 2) &&
		(boxPosA.y - boxA->size_.y / 2) < (boxPosB.y + boxB->size_.y / 2) &&
		(boxPosA.z + boxA->size_.z / 2) > (boxPosB.z - boxB->size_.z / 2) &&
		(boxPosA.z - boxA->size_.z / 2) < (boxPosB.z + boxB->size_.z / 2))
	{
		return true;
	}
	return false;
}

//箱型と球体の衝突判定
//引数：box	箱型判定
//引数：sphere	２つ目の箱型判定
//戻値：接触していればtrue
bool Collider::IsHitBoxVsCircle(BoxCollider* box, SphereCollider* sphere)
{
	XMFLOAT3 centerSphere = sphere->center_;
	XMFLOAT3 rotateSphere = sphere->rotate_;

	XMFLOAT3 centerBox = box->center_;
	XMFLOAT3 rotateBox = box->rotate_;
	
	
	ColliderRotate(centerSphere, rotateSphere);
	ColliderRotate(centerBox, rotateBox);
	

	XMFLOAT3 circlePos = Transform::Float3Add(sphere->pGameObject_->GetWorldPosition(), centerSphere);
	XMFLOAT3 boxPos = Transform::Float3Add(box->pGameObject_->GetWorldPosition(), rotateBox);



	if (circlePos.x > boxPos.x - box->size_.x - sphere->size_.x &&
		circlePos.x < boxPos.x + box->size_.x + sphere->size_.x &&
		circlePos.y > boxPos.y - box->size_.y - sphere->size_.x &&
		circlePos.y < boxPos.y + box->size_.y + sphere->size_.x &&
		circlePos.z > boxPos.z - box->size_.z - sphere->size_.x &&
		circlePos.z < boxPos.z + box->size_.z + sphere->size_.x )
	{
		return true;
	}

	return false;

}

//球体同士の衝突判定
//引数：circleA	１つ目の球体判定
//引数：circleB	２つ目の球体判定
//戻値：接触していればtrue
bool Collider::IsHitCircleVsCircle(SphereCollider* circleA, SphereCollider* circleB)
{
	XMFLOAT3 centerA = circleA->center_;
	XMFLOAT3 rotateA = circleA->rotate_;
	XMFLOAT3 positionA = circleA->pGameObject_->GetWorldPosition();

	XMFLOAT3 centerB = circleB->center_;
	XMFLOAT3 rotateB = circleB->rotate_;
	XMFLOAT3 positionB = circleB->pGameObject_->GetWorldPosition();

	ColliderRotate(centerA, rotateA);
	ColliderRotate(centerB, rotateB);

	XMVECTOR v = (XMLoadFloat3(&centerA) + XMLoadFloat3(&positionA))
		- (XMLoadFloat3(&centerB) + XMLoadFloat3(&positionB));

	if (XMVector3Length(v).m128_f32[0] <= circleA->size_.x + circleB->size_.x)
	{
		return true;
	}

	return false;
}

//テスト表示用の枠を描画
//引数：position	オブジェクトの位置
void Collider::Draw(XMFLOAT3 position, XMFLOAT3 rotate)
{
	Transform transform;
	transform.position_ = XMFLOAT3(position.x + center_.x, position.y + center_.y, position.z + center_.z);
	transform.rotate_ = XMFLOAT3(rotate.x + rotate_.x, rotate.y + rotate_.y, rotate.z + rotate_.z);
	//transform.rotate_ = XMFLOAT3(rotate);
	transform.scale_ = size_;
	transform.Calclation();
	Model::SetTransform(hDebugModel_, transform);
	Model::Draw(hDebugModel_);
}

void Collider::ColliderRotate(XMFLOAT3& center_, const XMFLOAT3& rotate)
{
	//回転行列の作成
	XMMATRIX rotationMatrix = XMMatrixRotationRollPitchYaw(rotate.x, rotate.y, rotate.z);

	//中心座標をXMVECTORに変換
	XMVECTOR centerVec = XMLoadFloat3(&center_);

	//回転
	XMVECTOR rotateCenter = XMVector3Transform(centerVec, rotationMatrix);

	XMStoreFloat3(&center_, rotateCenter);
}
