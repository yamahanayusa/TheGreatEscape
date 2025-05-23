#include "stdafx.h"
#include "Coin.h"
#include "Player.h"
#include "sound/SoundSource.h"
#include "sound/SoundEngine.h"

Coin::Coin()
{
	
}

Coin::~Coin()
{

}

bool Coin::Start() {
	//☆のモデルを読み込む。
	m_modelRender.Init("Assets/modelData/coin.tkm");
	m_player = FindGO<Player>("player");

	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/coin.wav");
	
	return true;
}

void Coin::Update()
{
	//移動処理。
	Move();

	//回転処理。
	Rotation();

	//絵描きさんの更新処理。
	m_modelRender.Update();

	//プレイヤーからコインに向かうベクトルを計算。
	Vector3 diff = m_player->m_position - m_position;

	//ベクトルの長さが120.0fより小さかったら。
	if (diff.Length() <= 120.0f)
	{
		//SoundSourceの作成。番号0。
		m_sound = NewGO<SoundSource>(0);
		//SoundSource0番を持ってくる。
		m_sound->Init(0);
		//falseにしてループを無くす。
		m_sound->Play(false);

		m_player->m_coinCount += 1;

		//自身を削除する。
		DeleteGO(this);
	}
}

void Coin::Move()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_position);
}

//回転処理。
void Coin::Rotation()
{
	//回転を加算する。
	m_rotation.AddRotationDegY(2.0f);

	//絵描きさんに回転を教える。
	m_modelRender.SetRotation(m_rotation);
}

void Coin::Render(RenderContext& rc)
{
	//coinを描画する。
	m_modelRender.Draw(rc);
}