#include "stdafx.h"
#include "Star.h"
#include "Player.h"

Star::Star()
{
	modelRender.Init("Assets/modelData/star.tkm");
	player = FindGO<Player>("player");
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
		DeleteGO(this);
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

	//絵描きさんに座標を教える。
	modelRender.SetPosition(position);
}

void Star::Rotation()
{
	//回転を加算する。
	rotation.AddRotationDegY(2.0f);

	//絵描きさんに回転を教える。
	modelRender.SetRotation(rotation);
}

void Star::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}