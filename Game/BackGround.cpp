#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	//�w�i�̃��f����ǂݍ��ށB
	modelRender.Init("Assets/modelData/stage/stage.tkm");
	//�X�V�����B
	modelRender.Update();
	//Collider(�����蔻��)�����B
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}

BackGround::~BackGround()
{

}

//�`�揈���B
void BackGround::Render(RenderContext& rc)
{
	//�w�i��`�悷��B
	modelRender.Draw(rc);
}