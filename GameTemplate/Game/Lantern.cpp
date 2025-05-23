#include "stdafx.h"
#include "Lantern.h"
#include "Player.h"

Lantern::Lantern()
{

}

Lantern::~Lantern()
{

}

bool Lantern::Start()
{
	m_modelRender.Init("Assets/modelData/Lantern.tkm");

	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.SetScale(m_scale);

	m_player = FindGO<Player>("player");

	// �X�|�b�g���C�g���������B
	m_spotLight.Init();
	//���C�g�̉e��������ݒ�B
	m_spotLight.SetRange(400.0f);
	//���C�g�̉e���p�x��ݒ�B
	m_spotLight.SetAngle(Math::DegToRad(35.0f));
	//���C�g�̋�����������ݒ�B
	m_spotLight.SetRangeAffectPowParam(0.4f);
	//���C�g�̊p�x��������ݒ�B
	m_spotLight.SetAngleAffectPowParam(0.7f);
	//���C�g�̐F��ݒ�B
	m_spotLight.SetColor(1.0f, 1.0f, 1.0f);
	
	return true;
}

void Lantern::Update()
{
	m_modelRender.Update();
	m_spotLight.Update();

	//���C�g�̍��W��ݒ�B
	m_spotLight.SetPosition(m_player->m_position + Vector3(0.0f, 50.0f, 0.0f));
	//���C�g�̕�����ݒ�B
	m_spotLight.SetDirection(m_player->m_forward);
	//���C�g���X�V�B
	m_spotLight.Update();
}

void Lantern::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}