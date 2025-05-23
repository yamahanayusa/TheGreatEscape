#pragma once

class Enemy1;
class Hp;

class Player : public IGameObject
{
public:
	Player();
	~Player();
	//�A�^�b�N�B
	void Atk();
	//�����ݒ�
	bool Start();
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);
	//�ړ������B
	void Move();
	//��]�����B
	void Rotation();
	//�X�e�[�g�Ǘ��B
	void ManageState();
	//�A�j���[�V�����̍Đ��B
	void PlayAnimation();

	Enemy1* m_enemy1 = nullptr;
	Hp* m_hp = nullptr;

	ModelRender m_modelRender;	//���f�������_�\�B
	CharacterController m_characterController;  //�L�����N�^�[�R���g���[���[�B

	Vector3 m_position = Vector3(0.0f, 0.0f, 10.0f);			//���W�B
	Vector3 m_moveSpeed;		//�ړ����x�B
	Quaternion m_rotation;  //�N�H�[�^�j�I���B
	Vector3	m_forward = Vector3::AxisZ; //���C�g�B

	int m_playerState = 0;	//�v���C���[�̃X�e�[�g(���)��\���ϐ��B
	int m_coinCount = 0;	//�W�߂����̐����J�E���g����B
	int m_invincibleTime = 120;	//���G���ԁB
	int m_hpCount = 0;		//hp�������������J�E���g����B

	enum EnAnimationClip {		//�A�j���[�V�����B
		enAnimationClip_Walk,
		enAnimationClip_Idle,
		enAnimationClip_Num,
	};
	AnimationClip m_animationClips[enAnimationClip_Num];		//�A�j���[�V�����N���b�v�B
	
};

