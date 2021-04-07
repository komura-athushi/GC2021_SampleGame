#include "stdafx.h"
#include "Star.h"
#include "Player.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Star::Star()
{
	modelRender.Init("Assets/modelData/star.tkm");
	player = FindGO<Player>("player");

	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/get.wav");
}

Star::~Star()
{

}

void Star::Update()
{
	Move();
	Rotation();

	Vector3 diff = player->position - position;
	if (diff.Length() <= 100.0f)
	{
		player->getStarNumber += 1;
		DeleteGO(this);
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(2);
		se->SetVolume(3.5f);
		se->Play(false);
	}

	modelRender.Update();
}

void Star::Move()
{
	if (moveCount == 0)
	{
		position.y += 1.0f;
	}
	else if (moveCount == 1)
	{
		position.y -= 1.0f;
	}

	if (position.y >= firstPosition.y + 50.0f)
	{
		moveCount = 1;
	}
	else if (position.y  <= firstPosition.y - 50.0f)
	{
		moveCount = 0;
	}

	//ŠG•`‚«‚³‚ñ‚ÉÀ•W‚ð‹³‚¦‚éB
	modelRender.SetPosition(position);
}

void Star::Rotation()
{
	//‰ñ“]‚ð‰ÁŽZ‚·‚éB
	rotation.AddRotationDegY(2.0f);

	//ŠG•`‚«‚³‚ñ‚É‰ñ“]‚ð‹³‚¦‚éB
	modelRender.SetRotation(rotation);
}

void Star::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}