#pragma once
class Player;
class Star : public IGameObject
{
public:
	Star();
	~Star();
	void Update();
	void Move();
	void Rotation();
	void Render(RenderContext& rc);

	ModelRender modelRender;
	Vector3 firstPosition;
	Vector3 position;
	int moveCount;
	Quaternion rotation;
	Player* player;
};

