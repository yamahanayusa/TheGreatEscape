#pragma once
class GameClear : public IGameObject
{
public:
	GameClear();
	~GameClear();
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);

	SpriteRender m_spriteRender;//�X�v���C�g�����_�[�B
};

