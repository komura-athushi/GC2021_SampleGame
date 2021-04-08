#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "Star.h"
#include "sound/SoundEngine.h"
#include "GameClear.h"

Game::Game()
{
	//プレイヤーのオブジェクトを作る。
	player = NewGO<Player>(0, "player");
	//背景のオブジェクトを作る。
	backGround = NewGO<BackGround>(0, "background");
	//ゲームカメラのオブジェクトを作る。
	gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//☆のオブジェクトを5つ作る。
	Star* star1 = NewGO<Star>(0, "star");
	//座標を設定する。
	star1->firstPosition = { 100.0f,150.0f,-200.0f };
	star1->position = { 100.0f,150.0f,-200.0f };

	Star* star2 = NewGO<Star>(0, "star");
	star2->firstPosition = { 1000.0f,150.0f,-200.0f };
	star2->position = { 1000.0f,150.0f,-200.0f };

	Star* star3 = NewGO<Star>(0, "star");
	star3->firstPosition = { 100.0f,250.0f,400.0f };
	star3->position = { 100.0f,250.0f,400.0f };

	Star* star4 = NewGO<Star>(0, "star");
	star4->firstPosition = { 2300.0f,50.0f,-200.0f };
	star4->position = { 2300.0f,50.0f,-200.0f };

	Star* star5 = NewGO<Star>(0, "star");
	star5->firstPosition = { 2700.0f,450.0f,400.0f };
	star5->position = { 2700.0f,450.0f,400.0f };

	//ゲーム中のBGMを読み込む。
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/gamebgm.wav");
	//ゲーム中のBGMを再生する。
	gameBGM = NewGO<SoundSource>(0);
	gameBGM->Init(1);
	gameBGM->Play(true);
}

Game::~Game()
{
	//プレイヤーを削除する。
	DeleteGO(player);
	//ゲームカメラを削除する。
	DeleteGO(gameCamera);
	//ゲーム中のBGMを削除する。
	DeleteGO(gameBGM);
	//背景を削除する。
	DeleteGO(backGround);
}

//更新処理。
void Game::Update()
{
	//プレイヤーの☆カウントが5(☆が全部削除された)になったら。
	if (player->starCount == 5)
	{
		//ゲームクリアのオブジェクトを作る。
		NewGO<GameClear>(0, "gamecleear");
		//自身を削除する。
		DeleteGO(this);
	}
}