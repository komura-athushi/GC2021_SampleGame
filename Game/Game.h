#pragma once
#include "sound/SoundSource.h"

class BackGround;
class Player;
class GameCamera;

//Game中を管理するクラス。
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//更新処理。
	void Update();

	BackGround* backGround;		//背景。
	Player* player;			//プレイヤー。
	GameCamera* gameCamera;			//ゲームカメラ。
	SoundSource* gameBGM;		//ゲーム中のBGM。
};

