#pragma once

class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& rc);
	void Move();
	void Rotation();
	void Animation();
	void State();

	ModelRender modelRender;
	Vector3 position;
	Vector3 moveSpeed;
	CharacterController characterController;
	Quaternion rotation;
	enum EnAnimationClip {
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Num,
	};
	AnimationClip animationClips[enAnimationClip_Num];
	int playerState = 0;
	int getStarNumber = 0;
};
