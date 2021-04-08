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
	//�v���C���[�̃I�u�W�F�N�g�����B
	player = NewGO<Player>(0, "player");
	//�w�i�̃I�u�W�F�N�g�����B
	backGround = NewGO<BackGround>(0, "background");
	//�Q�[���J�����̃I�u�W�F�N�g�����B
	gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//���̃I�u�W�F�N�g��5���B
	Star* star1 = NewGO<Star>(0, "star");
	//���W��ݒ肷��B
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

	//�Q�[������BGM��ǂݍ��ށB
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/gamebgm.wav");
	//�Q�[������BGM���Đ�����B
	gameBGM = NewGO<SoundSource>(0);
	gameBGM->Init(1);
	gameBGM->Play(true);
}

Game::~Game()
{
	//�v���C���[���폜����B
	DeleteGO(player);
	//�Q�[���J�������폜����B
	DeleteGO(gameCamera);
	//�Q�[������BGM���폜����B
	DeleteGO(gameBGM);
	//�w�i���폜����B
	DeleteGO(backGround);
}

//�X�V�����B
void Game::Update()
{
	//�v���C���[�́��J�E���g��5(�����S���폜���ꂽ)�ɂȂ�����B
	if (player->starCount == 5)
	{
		//�Q�[���N���A�̃I�u�W�F�N�g�����B
		NewGO<GameClear>(0, "gamecleear");
		//���g���폜����B
		DeleteGO(this);
	}
}