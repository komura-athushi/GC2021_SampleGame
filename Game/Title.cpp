#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"

Title::Title()
{
	spriteRender.Init("Assets/sprite/title.dds", 1280.0f, 720.0f);

	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/titlebgm.wav");
	bgm = NewGO<SoundSource>(0);
	bgm->Init(0);
	bgm->Play(true);
}

Title::~Title()
{
	DeleteGO(bgm);
}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}