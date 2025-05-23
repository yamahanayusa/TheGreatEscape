#include "stdafx.h"
#include "Enemy1.h"
#include "Player.h"
#include "Game.h"

Enemy1::Enemy1()
{
	//�A�j���[�V�����N���b�v�����[�h����B
	m_animationClips[enAnimationClip_Walk].Load("Assets/animData/enemy.tka");
	m_animationClips[enAnimationClip_Walk].SetLoopFlag(true);

	//���f���̓ǂݍ��݁B
	m_modelRender.Init("Assets/modelData/enemy.tkm", m_animationClips, enAnimationClip_Num,enModelUpAxisZ);

	//�G�̓���
	//m_rootPos[0] = {288.0f,1.0f,1062.0f};
	//m_rootPos[1] = {1070.0f,1.0f,1053.0f};
	//m_rootPos[2] = {-1109.0f,1.0f,10.0f};
	//m_rootPos[3] = {1092.0f,1.0f,52.0f};
	//m_rootPos[4] = {992.0f,1.0f,-1141.0f};
	//m_rootPos[5] = {207.0f,1.0f,-1090.0f};
	//m_rootPos[6] = {-207.0f,1.0f,-269.0f};
	//m_position = m_rootPos[0];
	m_modelRender.SetPosition(m_position);
	m_characterController.Init(10.0f, 40.0f, m_position);
	m_player = FindGO<Player>("player");
	m_game = FindGO<Game>("game");
}

Enemy1::~Enemy1()
{

}

//�X�V�����B
void Enemy1::Update()
{
	//�G�`������̍X�V�����B
	m_modelRender.Update();
	//�ړ������B
	Move();
	//�����B
	Rotation();
	//�x�N�g���̌v�Z�B
	m_EPvector = m_player->m_position - m_position;
}

void Enemy1::PlayAnimation()
{
	//�A�j���[�V�������Đ�����B
	m_modelRender.PlayAnimation(enAnimationClip_Walk);
}

void Enemy1::Move()
{
	//�G�`������ɍ��W��������B
	m_moveSpeed = m_EPvector;	//m_rootPos[m_nextPosNum] - m_rootPos[m_nowPosNum];
	m_moveSpeed.Normalize();
	m_moveSpeed *= 500.0f;	//�ړ��̃X�s�[�h�B

	//Vector3 diff = m_rootPos[m_nextPosNum] - m_position;
	//if (diff.Length() < 50.0f) {
	//	if (m_nextPosNum == m_rast) {
	//		m_nowPosNum = m_rast;
	//		m_nextPosNum = m_start;
	//	}
	//	m_nowPosNum = m_nextPosNum;
	//	m_nextPosNum++;

	//}

	//�L�����N�^�[�R���g���[���[���g���č��W���ړ�������B
	m_position = m_characterController.Execute(m_moveSpeed, 1.0f / 60.0f);
	m_modelRender.SetPosition(m_position);
}

void Enemy1::Rotation()
{
	Vector3 forward = Vector3::AxisZ;
	m_rot.Apply(forward);//�x�N�g���̒��̊p�x�𒊏o�B
	m_rot.SetRotationYFromDirectionXZ(m_EPvector);//�v���C���[�̕����Ɍ�������B
	m_modelRender.SetRotation(m_rot);//�ǂ��ɓ���邩�B
	
//	if (m_nowPosNum == 0) {
//		m_rot.SetRotationDegY(270.0f);
//	}
//	else if (m_nowPosNum == 1) {
//		m_rot.SetRotationDegY(90.0f);
//	}
//	else if (m_nowPosNum == 2) {
//		m_rot.SetRotationDegY(180.0f);
//	}
//	else if (m_nowPosNum == 3) {
//		m_rot.SetRotationDegY(0.0f);
//	}
//	else if (m_nowPosNum == 4) {
//		m_rot.SetRotationDegY(270.0f);
//	}
//	else if (m_nowPosNum == 5) {
//		m_rot.SetRotationDegY(0.0f);
//	}
//	m_modelRender.SetRotation(m_rot);
}

//�`�揈���B
void Enemy1::Render(RenderContext & rc)
{
	//���j�e�B������`�悷��B
	m_modelRender.Draw(rc);
}