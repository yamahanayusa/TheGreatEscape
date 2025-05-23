#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "Coin.h"
#include "GameCamera.h"
#include "GameClear.h"
#include "Enemy1.h"
#include "Hp.h"
#include "Lantern.h"
#include "GameOver.h"
#include "Door.h"
#include "sound/SoundSource.h"
#include "sound/SoundEngine.h"

Game::Game() 
{
	//BGMの再生。
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/nomalBGM.wav");
	//SoundSourceの作成。番号1。
	m_sound = NewGO<SoundSource>(1);

	//ステージを暗くする。
	g_sceneLight->SetAmbinet(Vector3(0.0003f, 0.0003f, 0.0003f));
	g_sceneLight->SetDirectionLight(0, Vector3::Zero, Vector3(1.0f,1.0f,1.0f));

	//当たり判定。
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	//ライトのオブジェクトを作る。
	m_lantern = NewGO<Lantern>(0, "lantern");

	//プレイヤーのオブジェクトを作る。
	m_player = NewGO<Player>(0, "player");

	//ゲームカメラのオブジェクトを作る。
	m_gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//敵のオブジェクトを作る。
	m_enemy1 = NewGO<Enemy1>(0, "enemy");
	m_enemy1->m_position = { 800.0f,0.0f,-200.0f };
	m_enemy1->m_firstPosition = m_enemy1->m_position;

	//背景のオブジェクトを作る。
	m_backGround = NewGO<BackGround>(0,"background");

	//HPオブジェクトを作る。
	m_hp = NewGO<Hp>(0,"hp");

	//Doorのオブジェクトを作る。
	m_door = NewGO<Door>(0, "door");

	//Coinクラスのオブジェクトを作る。
	Coin* coin1 = NewGO<Coin>(0, "coin");
	coin1->m_position = { 100.0f,3.0f,-200.0f };
	coin1->m_firstPosition = coin1->m_position;

	Coin* coin2 = NewGO<Coin>(0, "coin");
	coin2->m_position = { 1000.0f,3.0f,-200.0f };
	coin2->m_firstPosition = coin2->m_position;

	Coin* coin3 = NewGO<Coin>(0, "coin");
	coin3->m_position = { 100.0f,3.0f,400.0f };
	coin3->m_firstPosition = coin3->m_position;

	Coin* coin4 = NewGO<Coin>(0, "coin");
	coin4->m_position = { 230.0f,3.0f,-200.0f };
	coin4->m_firstPosition = coin4->m_position;

	Coin* coin5 = NewGO<Coin>(0, "coin");
	coin5->m_position = { 5880.0f,3.0f,30.0f };
	coin5->m_firstPosition = coin5->m_position;

	//SoundSource1番を持ってくる。
	m_sound->Init(1);
	//trueにしてループをさせる。
	m_sound->Play(true);
}

Game::~Game()
{
	//プレイヤーを削除する。
	DeleteGO(m_player);

	//背景を削除する。
	DeleteGO(m_backGround);

	//ゲームカメラを削除する。
	DeleteGO(m_gameCamera);

	//敵を削除する。
	DeleteGO(m_enemy1);

	//doorを削除する。
	DeleteGO(m_door);

	//音を消去する。
	DeleteGO(m_sound);

	//コインを消去する。
	DeleteGO(m_coin);

	//hpを消去する。
	DeleteGO(m_hp);
}

//更新処理。
void Game::Update()
{
	//コインを5つ取った時ゲームクリアを表示する。
	if (m_player->m_coinCount == 5) {
		NewGO<GameClear>(0);
		DeleteGO(this);
	}
	
	//プレイヤーのhpが3削れたらゲームオーバーを表示する。
	if (m_player->m_hpCount == 3) {
		NewGO<GameOver>(0);
		DeleteGO(this);
	}
}

void Game::Render(RenderContext& rc)
{

}