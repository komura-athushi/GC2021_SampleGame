#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"

GameClear::GameClear()
{
	//�Q�[���N���A�̉摜��ǂݍ��ށB
	spriteRender.Init("Assets/sprite/gameclear.dds",1280.0f,720.0f);
}

GameClear::~GameClear()
{

}

//�X�V�����B
void GameClear::Update()
{
	//A�{�^���������ꂽ��B
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//�^�C�g���̃I�u�W�F�N�g������B
		NewGO<Title>(0, "title");
		//���g���폜����B
		DeleteGO(this);
	}
}

//�`�揈���B
void GameClear::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}