#pragma once
class Player;
//☆クラス。
class Star : public IGameObject
{
public:
	Star();
	~Star();
	//更新処理。
	void Update();
	//移動処理。
	void Move();
	//回転処理。
	void Rotation();
	//描画処理。
	void Render(RenderContext& rc);

	//メンバ変数。
	ModelRender modelRender;	//モデルレンダ―。
	Vector3 firstPosition;		//最初の座標。
	Vector3 position;			//現在の座標。
	int moveCount;				//上に移動か下に移動か。
	Quaternion rotation;		//回転。	
	Player* player;				//プレイヤー。
};

