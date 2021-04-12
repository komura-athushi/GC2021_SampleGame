#include "stdafx.h"
#include "Player.h"

Player::Player()
{//�A�j���[�V�����N���b�v�����[�h����B
	animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	//���f��������������B
	modelRender.Init("Assets/modelData/unityChan.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

	//�L�����R��������������B
	characterController.Init(25.0f, 75.0f, position);
}

Player::~Player()
{

}

//�X�V�����B
void Player::Update()
{
	//�ړ������B
	Move();
	//��]�����B
	Rotation();
	//�A�j���[�V�����B
	PlayAnimation();
	//�X�e�[�g�����߂�B
	ManageState();

	//�G�`������̍X�V�����B
	modelRender.Update();
}

//�ړ������B
void Player::Move()
{
	//xz�̈ړ����x��0.0f�ɂ���B
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ��擾�B
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//�J�����̑O�����ƉE�������擾�B
	Vector3 front = g_camera3D->GetForward();
	front.y = 0.0f;
	Vector3 right = g_camera3D->GetRight();
	right.y = 0.0f;

	//�X�e�B�b�N�̓��͗ʂƃJ�����̑O�ƉE�����̃x�N�g�����B
	//�������킹�����̂��ړ����x�ɂ���B
	moveSpeed += front * stickL.y * 120.0f;
	moveSpeed += right * stickL.x * 120.0f;

	//�n�ʂɕt���Ă�����B
	if (characterController.IsOnGround())
	{
		//�d�͂𖳂����B
		moveSpeed.y = 0.0f;
		//A�{�^���������ꂽ��B
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//�W�����v������B
			moveSpeed.y = 240.0f;
		}
	}
	//�n�ʂɕt���Ă��Ȃ�������B
	else
	{
		//�d�͂𔭐�������B
		moveSpeed.y -= 2.5f;
	}
	//�L�����R���ړ�������B
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);
	//�G�`������ɍ��W��������B
	modelRender.SetPosition(position);
}

//��]�����B
void Player::Rotation()
{
	//x��z�̈ړ����x����������(�X�e�B�b�N�̓��͂���������)�B
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//�L�����N�^�[�̕�����ς���B
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//�G�`������ɉ�]��������B
		modelRender.SetRotation(rotation);
	}

}

//�A�j���[�V���������B
void Player::PlayAnimation()
{
	//switch���B
	switch (playerState) {
	//�v���C���[�X�e�[�g��0(�ҋ@)��������B
	case 0:
		//�ҋ@�A�j���[�V�������Đ�����B
		modelRender.PlayAnimation(enAnimationClip_Idle);
		break;
	//�v���C���[�X�e�[�g��1(�W�����v��)��������B
	case 1:
		//�W�����v�A�j���[�V�������Đ�����B
		modelRender.PlayAnimation(enAnimationClip_Jump);
		break;
	//�v���C���[�X�e�[�g��2(����)��������B
	case 2:
		//�����A�j���[�V�������Đ�����B
		modelRender.PlayAnimation(enAnimationClip_Walk);
		break;
	}
}

//�X�e�[�g�Ǘ��B
void Player::ManageState()
{
	//�n�ʂɕt���Ă��Ȃ�������B
	if (characterController.IsOnGround() == false)
	{
		//�X�e�[�g��1(�W�����v��)�ɂ���B
		playerState = 1;
		//������ManageState�̏������I��点��B
		return;
	}

	//�n�ʂɕt���Ă�����B
	//x��z�̈ړ����x����������(�X�e�B�b�N�̓��͂���������)�B
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//�X�e�[�g��2(����)�ɂ���B
		playerState = 2;
	}
	//x��z�̈ړ����x������������(�X�e�B�b�N�̓��͂�����������)�B
	else {
		//�X�e�[�g��0(�ҋ@)�ɂ���B
		playerState = 0;
	}
}

//�`�揈���B
void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}