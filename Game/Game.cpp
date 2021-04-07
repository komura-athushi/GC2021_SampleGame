#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "Star.h"

Game::Game()
{
	player = NewGO<Player>(0, "player");
	backGround = NewGO<BackGround>(0, "background");
	gameCamera = NewGO<GameCamera>(0, "gamecamera");

	Star* star1 = NewGO<Star>(0, "star");
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
}

Game::~Game()
{

}

void Game::Update()
{

}