#pragma once
#include "sound/SoundSource.h"

class BackGround;
class Player;
class GameCamera;

//Game�����Ǘ�����N���X�B
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//�X�V�����B
	void Update();

	BackGround* backGround;		//�w�i�B
	Player* player;			//�v���C���[�B
	GameCamera* gameCamera;			//�Q�[���J�����B
	SoundSource* gameBGM;		//�Q�[������BGM�B
};

