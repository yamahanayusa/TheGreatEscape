#pragma once

class Player;
//コインクラス
class Coin : public IGameObject
{
public:
	Coin();
	~Coin();
	bool Start();
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& rc);
	//移動処理。
	void Move();
	//回転処理。
	void Rotation();

	ModelRender m_modelRender;	//モデルレンダ―。
	Vector3 m_position;		//座標。
	Vector3 m_firstPosition;		//最初の座標。
	Quaternion m_rotation;	//クォータニオン。

	Player* m_player;		//プレイヤー。
	SoundSource* m_sound;   //音
};

