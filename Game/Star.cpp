#include "stdafx.h"
#include "Star.h"
#include "Player.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Star::Star()
{
	//☆のモデルを読み込む。
	modelRender.Init("Assets/modelData/star.tkm");
	//プレイヤーのオブジェクトを持ってくる。
	player = FindGO<Player>("player");

	//☆を削除する時の音を読み込む。
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/get.wav");
}

Star::~Star()
{

}

//更新処理。
void Star::Update()
{
	//移動処理。
	Move();
	//回転処理。
	Rotation();

	//プレイヤーから☆に向かうベクトルを計算。
	Vector3 diff = player->position - position;
	//ベクトルの長さが120.0fより小さかったら。
	if (diff.Length() <= 120.0f)
	{
		//効果音を再生する。
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(2);
		se->SetVolume(3.5f);
		se->Play(false);

		//プレイヤーの☆カウントを+1する。
		player->starCount += 1;
		//自身を削除する。
		DeleteGO(this);
	}

	//絵描きさんの描画処理。
	modelRender.Update();
}

//移動処理。
void Star::Move()
{
	//moveCountが0の時。
	if (moveCount == 0)
	{
		//上に移動させる。
		position.y += 1.0f;
	}
	//moveCountが1の時。
	else if (moveCount == 1)
	{
		//下に移動させる。
		position.y -= 1.0f;
	}

	//現在の座標が最初の座標より50.0f上に居たら。
	if (position.y >= firstPosition.y + 50.0f)
	{
		//moveCountを1(下移動)にする。
		moveCount = 1;
	}
	//現在の座標が最初の座標より50.0f下に居たら。
	else if (position.y  <= firstPosition.y - 50.0f)
	{
		//moveCountを0(上移動)にする。
		moveCount = 0;
	}

	//絵描きさんに座標を教える。
	modelRender.SetPosition(position);
}

//回転処理。
void Star::Rotation()
{
	//回転を加算する。
	rotation.AddRotationDegY(2.0f);

	//絵描きさんに回転を教える。
	modelRender.SetRotation(rotation);
}

//描画処理。
void Star::Render(RenderContext& rc)
{
	//☆を描画する。
	modelRender.Draw(rc);
}