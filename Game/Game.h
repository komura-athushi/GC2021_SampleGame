#pragma once
class BackGround;
class Player;
class GameCamera;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();


	BackGround* backGround;
	Player* player;
	GameCamera* gameCamera;
};

