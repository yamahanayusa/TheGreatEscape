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

	Lantern* m_lantern;//ライト。
	BackGround* m_backGround;//背景。
	Player* m_player;	//プレイヤー。
	GameCamera* m_gameCamera;	//ゲームカメラ。
	Enemy1* m_enemy1;//敵。
	Hp* m_hp;//体力。
	Door* m_door;//ドア。
	SoundSource* m_sound;//音
	Coin* m_coin;//コイン
};