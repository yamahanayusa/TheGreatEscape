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
	//BGM�̍Đ��B
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/nomalBGM.wav");
	//SoundSource�̍쐬�B�ԍ�1�B
	m_sound = NewGO<SoundSource>(1);

	//�X�e�[�W���Â�����B
	g_sceneLight->SetAmbinet(Vector3(0.0003f, 0.0003f, 0.0003f));
	g_sceneLight->SetDirectionLight(0, Vector3::Zero, Vector3(1.0f,1.0f,1.0f));

	//�����蔻��B
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	//���C�g�̃I�u�W�F�N�g�����B
	m_lantern = NewGO<Lantern>(0, "lantern");

	//�v���C���[�̃I�u�W�F�N�g�����B
	m_player = NewGO<Player>(0, "player");

	//�Q�[���J�����̃I�u�W�F�N�g�����B
	m_gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//�G�̃I�u�W�F�N�g�����B
	m_enemy1 = NewGO<Enemy1>(0, "enemy");
	m_enemy1->m_position = { 800.0f,0.0f,-200.0f };
	m_enemy1->m_firstPosition = m_enemy1->m_position;

	//�w�i�̃I�u�W�F�N�g�����B
	m_backGround = NewGO<BackGround>(0,"background");

	//HP�I�u�W�F�N�g�����B
	m_hp = NewGO<Hp>(0,"hp");

	//Door�̃I�u�W�F�N�g�����B
	m_door = NewGO<Door>(0, "door");

	//Coin�N���X�̃I�u�W�F�N�g�����B
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

	//SoundSource1�Ԃ������Ă���B
	m_sound->Init(1);
	//true�ɂ��ă��[�v��������B
	m_sound->Play(true);
}

Game::~Game()
{
	//�v���C���[���폜����B
	DeleteGO(m_player);

	//�w�i���폜����B
	DeleteGO(m_backGround);

	//�Q�[���J�������폜����B
	DeleteGO(m_gameCamera);

	//�G���폜����B
	DeleteGO(m_enemy1);

	//door���폜����B
	DeleteGO(m_door);

	//������������B
	DeleteGO(m_sound);

	//�R�C������������B
	DeleteGO(m_coin);

	//hp����������B
	DeleteGO(m_hp);
}

//�X�V�����B
void Game::Update()
{
	//�R�C����5��������Q�[���N���A��\������B
	if (m_player->m_coinCount == 5) {
		NewGO<GameClear>(0);
		DeleteGO(this);
	}
	
	//�v���C���[��hp��3��ꂽ��Q�[���I�[�o�[��\������B
	if (m_player->m_hpCount == 3) {
		NewGO<GameOver>(0);
		DeleteGO(this);
	}
}

void Game::Render(RenderContext& rc)
{

}