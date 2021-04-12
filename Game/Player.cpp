#include "stdafx.h"
#include "Player.h"

Player::Player()
{//アニメーションクリップをロードする。
	animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	//モデルを初期化する。
	modelRender.Init("Assets/modelData/unityChan.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

	//キャラコンを初期化する。
	characterController.Init(25.0f, 75.0f, position);
}

Player::~Player()
{

}

//更新処理。
void Player::Update()
{
	//移動処理。
	Move();
	//回転処理。
	Rotation();
	//アニメーション。
	PlayAnimation();
	//ステートを決める。
	ManageState();

	//絵描きさんの更新処理。
	modelRender.Update();
}

//移動処理。
void Player::Move()
{
	//xzの移動速度を0.0fにする。
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//左スティックの入力量を取得。
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//カメラの前方向と右方向を取得。
	Vector3 front = g_camera3D->GetForward();
	front.y = 0.0f;
	Vector3 right = g_camera3D->GetRight();
	right.y = 0.0f;

	//スティックの入力量とカメラの前と右方向のベクトルを。
	//かけ合わせたものを移動速度にする。
	moveSpeed += front * stickL.y * 120.0f;
	moveSpeed += right * stickL.x * 120.0f;

	//地面に付いていたら。
	if (characterController.IsOnGround())
	{
		//重力を無くす。
		moveSpeed.y = 0.0f;
		//Aボタンが押されたら。
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//ジャンプさせる。
			moveSpeed.y = 240.0f;
		}
	}
	//地面に付いていなかったら。
	else
	{
		//重力を発生させる。
		moveSpeed.y -= 2.5f;
	}
	//キャラコン移動させる。
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);
	//絵描きさんに座標を教える。
	modelRender.SetPosition(position);
}

//回転処理。
void Player::Rotation()
{
	//xかzの移動速度があったら(スティックの入力があったら)。
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//キャラクターの方向を変える。
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//絵描きさんに回転を教える。
		modelRender.SetRotation(rotation);
	}

}

//アニメーション処理。
void Player::PlayAnimation()
{
	//switch文。
	switch (playerState) {
	//プレイヤーステートが0(待機)だったら。
	case 0:
		//待機アニメーションを再生する。
		modelRender.PlayAnimation(enAnimationClip_Idle);
		break;
	//プレイヤーステートが1(ジャンプ中)だったら。
	case 1:
		//ジャンプアニメーションを再生する。
		modelRender.PlayAnimation(enAnimationClip_Jump);
		break;
	//プレイヤーステートが2(歩き)だったら。
	case 2:
		//歩きアニメーションを再生する。
		modelRender.PlayAnimation(enAnimationClip_Walk);
		break;
	}
}

//ステート管理。
void Player::ManageState()
{
	//地面に付いていなかったら。
	if (characterController.IsOnGround() == false)
	{
		//ステートを1(ジャンプ中)にする。
		playerState = 1;
		//ここでManageStateの処理を終わらせる。
		return;
	}

	//地面に付いていたら。
	//xかzの移動速度があったら(スティックの入力があったら)。
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//ステートを2(歩き)にする。
		playerState = 2;
	}
	//xとzの移動速度が無かったら(スティックの入力が無かったら)。
	else {
		//ステートを0(待機)にする。
		playerState = 0;
	}
}

//描画処理。
void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}