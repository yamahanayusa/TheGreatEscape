#pragma once

//�^�C�g���B
class Title : public IGameObject
{
public:
	Title();
	~Title();
	//�X�V�����B
	void Update();
	void Render(RenderContext& rc);

	SpriteRender m_spriteRender;
};