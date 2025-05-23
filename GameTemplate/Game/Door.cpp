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

	//ドアのpositionをセットする。
	m_doorModel.SetPosition(m_position);

	//当たり判定。
	m_physicsStaticObject.CreateFromModel(m_doorModel.GetModel(), m_doorModel.GetModel().GetWorldMatrix());

	m_player = FindGO<Player>("player");

	return true;
}

void Door::Update() 
{
	//ドアの移動処理。
	Move();
	//絵描きさんの更新処理。
	m_doorModel.Update();
	
}

void Door::ReleasePhysicsObject()
{
	//当たり判定を開放する。
	m_physicsStaticObject.Release();
}

//ドア移動の関数
void Door::Move() 
{
	//プレイヤーがコインを１つ取るたびにドアの高さを50上げる。
	m_position.y = (m_player->m_coinCount + 1.0f) * 50.0f;
	//ドアのpositionをセットする。
	m_doorModel.SetPosition(m_position);

	//コインを４つ取ったら当たり判定をなくす。
	if(	m_player->m_coinCount == 4)
	{
		//当たり判定を開放する。
		ReleasePhysicsObject();
	}
}

void Door::Render(RenderContext& rc)
{
	//doorを描画する
	m_doorModel.Draw(rc);
}
