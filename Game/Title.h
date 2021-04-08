#pragma once
#include "sound/SoundSource.h"

//タイトル。
class Title : public IGameObject
{
public:
	Title();
	~Title();
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& rc);

	//メンバ変数。
	SpriteRender spriteRender;		//スプライトレンダ―。
	SoundSource* titleBGM;			//タイトルのBGM。
};

