#include "stdafx.h"
#include "Player.h"
#include "Enemy1.h"
#include "Hp.h"


Player::Player()
{


}

Player::~Player()
{

}

bool Player::Start()
{
	//�A�j���[�V�����N���b�v�����[�h����B
	m_animationClips[enAnimationClip_Walk].Load("Assets/animData/player.tka");
	m_animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Idle].Load("Assets/animData/playeridle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	//player�̃��f����ǂݍ��ށB
	m_modelRender.Init("Assets/modelData/Player.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisZ);
	//�L�����R��������������B
	m_characterController.Init(25.0f, 75.0f, m_position);

	m_enemy1 = FindGO<Enemy1>("enemy");
	m_hp = FindGO<Hp>("hp");
	return true;
}

//�X�V�����B
void Player::Update()
{
	//hp�B
	Atk();

	//�ړ������B
	Move();

	//��]�����B
	Rotation();

	//�X�e�[�g�Ǘ��B
	ManageState();

	//�A�j���[�V�����̍Đ��B
	PlayAnimation();
	
	//�G�`������̍X�V�����B
	m_modelRender.Update();
}

void Player::Atk()
{
	Vector3 distance;//�G�ƃv���C���[�̋����B
	distance = m_position - m_enemy1->m_position;

	if (distance.Length() <= 70.0f) {
		if (m_invincibleTime <= 0) {
			m_hp->Hit();
			m_invincibleTime = 120;
		}
	}
	if (m_invincibleTime >= 0){
		m_invincibleTime -= g_gameTime->GetFrameDeltaTime();
	}
		
}

//�ړ������B
void Player::Move()
{
	//xz�̈ړ����x��0.0f�ɂ���B
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ��擾�B
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//�J�����̑O�����ƉE�����̃x�N�g���������Ă���B
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	//y�����ɂ͈ړ������Ȃ��B
	forward.y = 0.0f;
	right.y = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ�520.0f����Z�B
	right *= stickL.x * 700.0f;
	forward *= stickL.y * 700.0f;

	//�ړ����x�ɃX�e�B�b�N�̓��͗ʂ����Z����B
	m_moveSpeed += right + forward;

	//�n�ʂɕt���Ă�����B
	if (m_characterController.IsOnGround())
	{
		//�d�͂𖳂����B
		m_moveSpeed.y = 0.0f;
		//A�{�^���������ꂽ��B
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//�W�����v������B
			m_moveSpeed.y = 100.0f;
		}
	}
	//�n�ʂɕt���Ă��Ȃ�������B
	else
	{
		//�d�͂𔭐�������B
		m_moveSpeed.y -= 6.0f;
	}

	//�L�����N�^�[�R���g���[���[���g���č��W���ړ�������B
	m_position = m_characterController.Execute(m_moveSpeed, 1.0f / 60.0f);

	//�G�`������ɍ��W��������B
	m_modelRender.SetPosition(m_position);
}

void Player::Rotation()
{
	//x��z�̈ړ����x����������(�X�e�B�b�N�̓��͂���������)�B
	if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	{
		//�L�����N�^�[�̕�����ς���B
		m_rotation.SetRotationYFromDirectionXZ(m_moveSpeed);
		//�G�`������ɉ�]��������B
		m_modelRender.SetRotation(m_rotation);
		//Player�̐��ʂ������Ă���B
		m_forward = Vector3::AxisZ;
		m_rotation.Apply(m_forward);
	}
}

//�X�e�[�g�Ǘ��B
void Player::ManageState()
{
	//�n�ʂɕt���Ă��Ȃ�������B
	if (m_characterController.IsOnGround() == false)
	{
		//�X�e�[�g��1(�W�����v��)�ɂ���B
		m_playerState = 1;
		//������ManageState�̏������I��点��B
		return;
	}

	//�n�ʂɕt���Ă�����B
	//x��z�̈ړ����x����������(�X�e�B�b�N�̓��͂���������)�B
	if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	{
		//�X�e�[�g��2(����)�ɂ���B
		m_playerState = 2;
	}
	//x��z�̈ړ����x������������(�X�e�B�b�N�̓��͂�����������)�B
	else
	{
		//�X�e�[�g��0(�ҋ@)�ɂ���B
		m_playerState = 0;
	}
}

//�A�j���[�V�����̍Đ��B
void Player::PlayAnimation()
{
	//switch���B
	switch (m_playerState) {
		//�v���C���[�X�e�[�g��0(�ҋ@)��������B
	case 0:
		//�ҋ@�A�j���[�V�������Đ�����
		m_modelRender.PlayAnimation(enAnimationClip_Idle);
		break;
		//�v���C���[�X�e�[�g��1(�W�����v��)��������B
	case 1:
		//�W�����v�A�j���[�V�������Đ�����B
		//m_modelRender.PlayAnimation(enAnimationClip_Jump);
		break;
		//�v���C���[�X�e�[�g��2(����)��������B
	case 2:
		//�����A�j���[�V�������Đ�����B
		m_modelRender.PlayAnimation(enAnimationClip_Walk);
		break;
	}
}

//�`�揈���B
void Player::Render(RenderContext& rc)
{
	//���j�e�B������`�悷��B
	m_modelRender.Draw(rc);
}