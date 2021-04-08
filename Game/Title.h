#pragma once
#include "sound/SoundSource.h"

//�^�C�g���B
class Title : public IGameObject
{
public:
	Title();
	~Title();
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);

	//�����o�ϐ��B
	SpriteRender spriteRender;		//�X�v���C�g�����_�\�B
	SoundSource* titleBGM;			//�^�C�g����BGM�B
};

