#pragma once
class Player;
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	void Update();

	Player* player;
	Vector3 position;
	Vector3 targetPosition;
	Vector3 moveSpeed;
	float degreeY = 0.0f;
	float degreeXZ = 0.0f;
};

