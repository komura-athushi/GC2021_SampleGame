#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"

Title::Title()
{
	//�^�C�g���̉摜��ǂݍ��ށB
	spriteRender.Init("Assets/sprite/title.dds", 1280.0f, 720.0f);

	//�^�C�g����BGM��ǂݍ��ށB
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/titlebgm.wav");
	//�^�C�g����BGM���Đ�����B
	titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(0);
	titleBGM->Play(true);
}

Title::~Title()
{
	//�^�C�g����BGM���폜����B
	DeleteGO(titleBGM);
}

void Title::Update()
{
	//A�{�^���������ꂽ��B
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//�Q�[���̃I�u�W�F�N�g�����B
		NewGO<Game>(0, "game");
		//���g���폜����B
		DeleteGO(this);
	}
}

//�`�揈���B
void Title::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}