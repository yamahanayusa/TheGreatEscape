#pragma once

class Player;

class Hp :public IGameObject
{
public:
	Hp();
	~Hp();
	bool Start();
	//�X�V�����B
	void Update();
	//hp�B
	void Hit();
	//�`�揈���B
	void Render(RenderContext& rc);

	SpriteRender m_spriteRender[3];
	Player* m_player;	//�v���C���[�B
	int m_health = 3;	//hp�B
};