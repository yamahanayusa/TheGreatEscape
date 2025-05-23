#include "stdafx.h"
#include "Door.h"
#include "Player.h"

Door::Door()
{

}

Door::~Door()
{

}

bool Door::Start() 
{
	m_doorModel.Init("Assets/modelData/tetugousi.tkm");

	//�h�A��position���Z�b�g����B
	m_doorModel.SetPosition(m_position);

	//�����蔻��B
	m_physicsStaticObject.CreateFromModel(m_doorModel.GetModel(), m_doorModel.GetModel().GetWorldMatrix());

	m_player = FindGO<Player>("player");

	return true;
}

void Door::Update() 
{
	//�h�A�̈ړ������B
	Move();
	//�G�`������̍X�V�����B
	m_doorModel.Update();
	
}

void Door::ReleasePhysicsObject()
{
	//�����蔻����J������B
	m_physicsStaticObject.Release();
}

//�h�A�ړ��̊֐�
void Door::Move() 
{
	//�v���C���[���R�C�����P��邽�тɃh�A�̍�����50�グ��B
	m_position.y = (m_player->m_coinCount + 1.0f) * 50.0f;
	//�h�A��position���Z�b�g����B
	m_doorModel.SetPosition(m_position);

	//�R�C�����S������瓖���蔻����Ȃ����B
	if(	m_player->m_coinCount == 4)
	{
		//�����蔻����J������B
		ReleasePhysicsObject();
	}
}

void Door::Render(RenderContext& rc)
{
	//door��`�悷��
	m_doorModel.Draw(rc);
}
