#include "stdafx.h"
#include "Star.h"
#include "Player.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Star::Star()
{
	//���̃��f����ǂݍ��ށB
	modelRender.Init("Assets/modelData/star.tkm");
	//�v���C���[�̃I�u�W�F�N�g�������Ă���B
	player = FindGO<Player>("player");

	//�����폜���鎞�̉���ǂݍ��ށB
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/get.wav");
}

Star::~Star()
{

}

//�X�V�����B
void Star::Update()
{
	//�ړ������B
	Move();
	//��]�����B
	Rotation();

	//�v���C���[���灙�Ɍ������x�N�g�����v�Z�B
	Vector3 diff = player->position - position;
	//�x�N�g���̒�����120.0f��菬����������B
	if (diff.Length() <= 120.0f)
	{
		//���ʉ����Đ�����B
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(2);
		se->SetVolume(3.5f);
		se->Play(false);

		//�v���C���[�́��J�E���g��+1����B
		player->starCount += 1;
		//���g���폜����B
		DeleteGO(this);
	}

	//�G�`������̕`�揈���B
	modelRender.Update();
}

//�ړ������B
void Star::Move()
{
	//moveCount��0�̎��B
	if (moveCount == 0)
	{
		//��Ɉړ�������B
		position.y += 1.0f;
	}
	//moveCount��1�̎��B
	else if (moveCount == 1)
	{
		//���Ɉړ�������B
		position.y -= 1.0f;
	}

	//���݂̍��W���ŏ��̍��W���50.0f��ɋ�����B
	if (position.y >= firstPosition.y + 50.0f)
	{
		//moveCount��1(���ړ�)�ɂ���B
		moveCount = 1;
	}
	//���݂̍��W���ŏ��̍��W���50.0f���ɋ�����B
	else if (position.y  <= firstPosition.y - 50.0f)
	{
		//moveCount��0(��ړ�)�ɂ���B
		moveCount = 0;
	}

	//�G�`������ɍ��W��������B
	modelRender.SetPosition(position);
}

//��]�����B
void Star::Rotation()
{
	//��]�����Z����B
	rotation.AddRotationDegY(2.0f);

	//�G�`������ɉ�]��������B
	modelRender.SetRotation(rotation);
}

//�`�揈���B
void Star::Render(RenderContext& rc)
{
	//����`�悷��B
	modelRender.Draw(rc);
}