#pragma once

//�v���C���[�N���X�B
class Player : public IGameObject
{
public:
	Player();
	~Player();

	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);
	//�ړ������B
	void Move();
	//��]�����B
	void Rotation();
	//�A�j���[�V���������B
	void Animation();
	//�X�e�[�g�Ǘ��B
	void ManageState();

	//�����o�ϐ��B
	ModelRender modelRender;	//���f�������_�\�B
	Vector3 position;			//���W�B
	Vector3 moveSpeed;			//�ړ������B
	CharacterController characterController;		//�L�����R���B
	Quaternion rotation;			//��]�����B
	enum EnAnimationClip {		//�A�j���[�V�����B
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Num,
	};
	AnimationClip animationClips[enAnimationClip_Num];		//�A�j���[�V�����N���b�v�B
	int playerState = 0;		//�v���C���[�X�e�[�g(�v���C���[�̏��)	�B
	int starCount = 0;			//�l���������̐��B
};
