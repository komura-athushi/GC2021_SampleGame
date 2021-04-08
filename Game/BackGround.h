#pragma once

//背景。
class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();
	//描画処理。
	void Render(RenderContext& rc);

	ModelRender modelRender;		//モデルレンダ―。
	PhysicsStaticObject physicsStaticObject;		//フィジックススタティックオブジェクト(あたり判定)。
};

