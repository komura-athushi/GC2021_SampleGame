#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	//”wŒi‚Ìƒ‚ƒfƒ‹‚ğ“Ç‚İ‚ŞB
	modelRender.Init("Assets/modelData/stage/stage.tkm");
	//XVˆ—B
	modelRender.Update();
	//Collider(‚ ‚½‚è”»’è)‚ğì‚éB
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}

BackGround::~BackGround()
{

}

//•`‰æˆ—B
void BackGround::Render(RenderContext& rc)
{
	//”wŒi‚ğ•`‰æ‚·‚éB
	modelRender.Draw(rc);
}