#pragma once

class Player;

class Door : public IGameObject
{
public:
	Door();
	~Door();
	bool Start();
	void Update();
	void Move();
	void ReleasePhysicsObject();
	void Render(RenderContext& rc);

	Vector3 m_position;
	Vector3 m_firstPosition;	//�ŏ���position�B

	PhysicsStaticObject m_physicsStaticObject;	//�����蔻��B
	ModelRender m_doorModel;	//���f�������_�\�B

	Player* m_player;	//�v���C���[�B
};

