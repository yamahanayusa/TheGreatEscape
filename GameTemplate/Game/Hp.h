#pragma once

class Player;

class Hp :public IGameObject
{
public:
	Hp();
	~Hp();
	bool Start();
	//更新処理。
	void Update();
	//hp。
	void Hit();
	//描画処理。
	void Render(RenderContext& rc);

	SpriteRender m_spriteRender[3];
	Player* m_player;	//プレイヤー。
	int m_health = 3;	//hp。
};