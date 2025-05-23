#pragma once

class Player;
//�R�C���N���X
class Coin : public IGameObject
{
public:
	Coin();
	~Coin();
	bool Start();
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);
	//�ړ������B
	void Move();
	//��]�����B
	void Rotation();

	ModelRender m_modelRender;	//���f�������_�\�B
	Vector3 m_position;		//���W�B
	Vector3 m_firstPosition;		//�ŏ��̍��W�B
	Quaternion m_rotation;	//�N�H�[�^�j�I���B

	Player* m_player;		//�v���C���[�B
	SoundSource* m_sound;   //��
};

