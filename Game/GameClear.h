#pragma once
//�Q�[���N���A�B
class GameClear : public IGameObject
{
public:
	GameClear();
	~GameClear();
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);

	//�����o�ϐ��B
	SpriteRender spriteRender;		//�X�v���C�g�����_�\�B
};

