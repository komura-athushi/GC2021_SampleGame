#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{
	player = FindGO<Player>("player");
}

GameCamera::~GameCamera()
{

}

void GameCamera::Update()
{
	//�v���C���[�̍��W���擾
	Vector3 playerPosition = player->position;

	targetPosition = playerPosition;
	targetPosition.y += 50.0f;

	//�E�X�e�B�b�N�̓��͗ʂ��擾
	Vector3 stickR;
	stickR.x = g_pad[0]->GetRStickXF();
	stickR.y = g_pad[0]->GetRStickYF();

	degreeY += stickR.x;
	degreeXZ -= stickR.y;

	if (degreeXZ >= 70.0f)
	{
		degreeXZ = 70.0f;
	}
	else if (degreeXZ <= 20.0f)
	{
		degreeXZ = 20.0f;
	}

	//Y���̉�]���v�Z�B
	Quaternion rotationY;
	rotationY.SetRotationDegY(degreeY);
	Vector3 toPos = Vector3::AxisZ;
	rotationY.Apply(toPos);
	//XZ���̉�]���v�Z�B
	Vector3 rotAxis;
	rotAxis.Cross(toPos, Vector3::AxisY);
	//�x�N�g���𐳋K������B
	rotAxis.Normalize();
	Quaternion rotationXZ;
	rotationXZ.SetRotationDeg(rotAxis, degreeXZ);
	rotationXZ.Apply(toPos);

	position = playerPosition + toPos * 350.0f;

	g_camera3D->SetTarget(targetPosition);
	g_camera3D->SetPosition(position);
}