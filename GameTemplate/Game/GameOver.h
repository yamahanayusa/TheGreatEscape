#pragma once

class Hp;
class GameOver :public IGameObject
{
public:
	GameOver();
	~GameOver();

	bool Start();
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);
	
	SpriteRender m_spriteRender;//�X�v���C�g�����_�[�B

	Hp* m_hp = nullptr;
};

