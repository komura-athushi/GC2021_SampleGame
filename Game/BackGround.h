#pragma once

//�w�i�B
class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();
	//�`�揈���B
	void Render(RenderContext& rc);

	ModelRender modelRender;		//���f�������_�\�B
	PhysicsStaticObject physicsStaticObject;		//�t�B�W�b�N�X�X�^�e�B�b�N�I�u�W�F�N�g(�����蔻��)�B
};

