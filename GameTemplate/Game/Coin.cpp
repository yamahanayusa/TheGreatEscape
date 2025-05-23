#include "stdafx.h"
#include "Coin.h"
#include "Player.h"
#include "sound/SoundSource.h"
#include "sound/SoundEngine.h"

Coin::Coin()
{
	
}

Coin::~Coin()
{

}

bool Coin::Start() {
	//���̃��f����ǂݍ��ށB
	m_modelRender.Init("Assets/modelData/coin.tkm");
	m_player = FindGO<Player>("player");

	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/coin.wav");
	
	return true;
}

void Coin::Update()
{
	//�ړ������B
	Move();

	//��]�����B
	Rotation();

	//�G�`������̍X�V�����B
	m_modelRender.Update();

	//�v���C���[����R�C���Ɍ������x�N�g�����v�Z�B
	Vector3 diff = m_player->m_position - m_position;

	//�x�N�g���̒�����120.0f��菬����������B
	if (diff.Length() <= 120.0f)
	{
		//SoundSource�̍쐬�B�ԍ�0�B
		m_sound = NewGO<SoundSource>(0);
		//SoundSource0�Ԃ������Ă���B
		m_sound->Init(0);
		//false�ɂ��ă��[�v�𖳂����B
		m_sound->Play(false);

		m_player->m_coinCount += 1;

		//���g���폜����B
		DeleteGO(this);
	}
}

void Coin::Move()
{
	//�G�`������ɍ��W��������B
	m_modelRender.SetPosition(m_position);
}

//��]�����B
void Coin::Rotation()
{
	//��]�����Z����B
	m_rotation.AddRotationDegY(2.0f);

	//�G�`������ɉ�]��������B
	m_modelRender.SetRotation(m_rotation);
}

void Coin::Render(RenderContext& rc)
{
	//coin��`�悷��B
	m_modelRender.Draw(rc);
}