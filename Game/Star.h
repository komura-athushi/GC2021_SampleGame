#pragma once
class Player;
//���N���X�B
class Star : public IGameObject
{
public:
	Star();
	~Star();
	//�X�V�����B
	void Update();
	//�ړ������B
	void Move();
	//��]�����B
	void Rotation();
	//�`�揈���B
	void Render(RenderContext& rc);

	//�����o�ϐ��B
	ModelRender modelRender;	//���f�������_�\�B
	Vector3 firstPosition;		//�ŏ��̍��W�B
	Vector3 position;			//���݂̍��W�B
	int moveCount;				//��Ɉړ������Ɉړ����B
	Quaternion rotation;		//��]�B	
	Player* player;				//�v���C���[�B
};

