#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	//背景のモデルを読み込む。
	modelRender.Init("Assets/modelData/stage/stage.tkm");
	//更新処理。
	modelRender.Update();
	//Collider(あたり判定)を作る。
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
}

BackGround::~BackGround()
{

}

//描画処理。
void BackGround::Render(RenderContext& rc)
{
	//背景を描画する。
	modelRender.Draw(rc);
}