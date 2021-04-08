#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"

Title::Title()
{
	//タイトルの画像を読み込む。
	spriteRender.Init("Assets/sprite/title.dds", 1280.0f, 720.0f);

	//タイトルのBGMを読み込む。
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/titlebgm.wav");
	//タイトルのBGMを再生する。
	titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(0);
	titleBGM->Play(true);
}

Title::~Title()
{
	//タイトルのBGMを削除する。
	DeleteGO(titleBGM);
}

void Title::Update()
{
	//Aボタンが押されたら。
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//ゲームのオブジェクトを作る。
		NewGO<Game>(0, "game");
		//自身を削除する。
		DeleteGO(this);
	}
}

//描画処理。
void Title::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}