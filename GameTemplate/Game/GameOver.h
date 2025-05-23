#pragma once

class Hp;
class GameOver :public IGameObject
{
public:
	GameOver();
	~GameOver();

	bool Start();
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& rc);
	
	SpriteRender m_spriteRender;//スプライトレンダー。

	Hp* m_hp = nullptr;
};

