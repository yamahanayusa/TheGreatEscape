#include "stdafx.h"
#include "Hp.h"
#include "Player.h"

Hp::Hp() 
{
	
}

Hp::~Hp() 
{

}

bool Hp::Start()
{
	//hp‰æ‘œ‚Ì“Ç‚İ‚İB
	for (int i = 0;i < 3;i++) {
		m_spriteRender[i].Init("Assets/sprite/raifu.DDS", 80.0f, 80.0f);
	}
	m_player = FindGO<Player>("player");
	//position‚Ìİ’èB
	m_spriteRender[0].SetPosition(Vector3(-850.0f, 400.0f, 0.0f));
	m_spriteRender[1].SetPosition(Vector3(-770.0f, 400.0f, 0.0f));
	m_spriteRender[2].SetPosition(Vector3(-690.0f, 400.0f, 0.0f));
	for (int i = 0;i < 3;i++) {
		m_spriteRender[i].Update();
	}
	return true;
}

void Hp::Update()
{
	
}

void Hp::Hit()
{
	if (m_health > 0) {
		m_health -= 1;
		m_spriteRender[m_health].Init("Assets/sprite/dethraifu.DDS", 80.0f, 80.0f);
		m_spriteRender[m_health].Update();
		m_player->m_hpCount += 1;
	}
}

void Hp::Render(RenderContext& rc)
{
	for (int i = 0;i < 3;i++) {
		m_spriteRender[i].Draw(rc);
	}	
}