#include "stdafx.h"
#include "Title.h"
#include "Game.h"

Title::Title()
{
	m_spriteRender.Init("Assets/sprite/Title.DDS", 1920.0f, 1080.0f);
}

Title::~Title()
{
}

void Title::Update()
{
	//A�{�^���������ꂽ��V�����Q�[�����n�߂�B
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}