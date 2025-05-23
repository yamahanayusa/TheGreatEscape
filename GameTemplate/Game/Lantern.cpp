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

	// スポットライトを初期化。
	m_spotLight.Init();
	//ライトの影響距離を設定。
	m_spotLight.SetRange(400.0f);
	//ライトの影響角度を設定。
	m_spotLight.SetAngle(Math::DegToRad(35.0f));
	//ライトの距離減衰率を設定。
	m_spotLight.SetRangeAffectPowParam(0.4f);
	//ライトの角度減衰率を設定。
	m_spotLight.SetAngleAffectPowParam(0.7f);
	//ライトの色を設定。
	m_spotLight.SetColor(1.0f, 1.0f, 1.0f);
	
	return true;
}

void Lantern::Update()
{
	m_modelRender.Update();
	m_spotLight.Update();

	//ライトの座標を設定。
	m_spotLight.SetPosition(m_player->m_position + Vector3(0.0f, 50.0f, 0.0f));
	//ライトの方向を設定。
	m_spotLight.SetDirection(m_player->m_forward);
	//ライトを更新。
	m_spotLight.Update();
}

void Lantern::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}