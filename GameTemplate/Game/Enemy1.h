#pragma once

class Player;
class Game;
class Enemy1:public IGameObject
{
public:
	Enemy1();
	~Enemy1();
	void Update();
	void Rotation();
	//�`�揈���B
	void Render(RenderContext& rc);
	//�A�j���[�V�����̍Đ��B
	void PlayAnimation();
	
	//�ړ������B
	void Move();
	

	enum EnAnimationClip {		//�A�j���[�V�����B
		enAnimationClip_Walk,
		enAnimationClip_Num,
	};

	Vector3		m_position = Vector3(300.0f,0.0f,0.0f);		//���W�B
	Vector3		m_firstPosition;	//�ŏ��̍��W�B
	Vector3		m_moveSpeed;
	Vector3     m_EPvector;	//�G����v���C���[�Ɍ������x�N�g���B
	//Vector3     m_rootPos[7];
	//int m_nowPosNum = 0;
	//int m_nextPosNum = 1;

	ModelRender m_modelRender;
	CharacterController m_characterController;  //�L�����N�^�[�R���g���[���[�B
	AnimationClip m_animationClips[enAnimationClip_Num];
	Quaternion m_rot;
	Player* m_player;
	Game* m_game;

	//�ŏ��̒n�_�B
	//int m_start = 0;
	//�ŏI�̒n�_�B
	//int m_rast = 6;
};

