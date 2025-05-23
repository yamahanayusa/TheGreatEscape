#pragma once

//タイトル。
class Title : public IGameObject
{
public:
	Title();
	~Title();
	//更新処理。
	void Update();
	void Render(RenderContext& rc);

	SpriteRender m_spriteRender;
};