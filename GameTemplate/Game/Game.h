#pragma once

#include "Level3DRender/LevelRender.h"

class Lantern;
class Player;
class GameCamera;
class BackGround;
class Enemy1;
class Hp;
class Door;
class Coin;
 
class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	void Render(RenderContext& rc);

private:
	Vector3 m_pos;

	Lantern* m_lantern;//���C�g�B
	BackGround* m_backGround;//�w�i�B
	Player* m_player;	//�v���C���[�B
	GameCamera* m_gameCamera;	//�Q�[���J�����B
	Enemy1* m_enemy1;//�G�B
	Hp* m_hp;//�̗́B
	Door* m_door;//�h�A�B
	SoundSource* m_sound;//��
	Coin* m_coin;//�R�C��
};