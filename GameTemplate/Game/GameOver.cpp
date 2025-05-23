#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"

GameOver::GameOver()
{

}

GameOver::~GameOver() 
{

}

bool GameOver::Start() 
{
    //�Q�[���N���A�̉摜��ǂݍ��ށB
    m_spriteRender.Init("Assets/sprite/GameOver.DDS", 1920.0f, 1080.0f);

    return true;
}

void GameOver::Update()
{
    //A�{�^���������ꂽ��B
    if (g_pad[0]->IsTrigger(enButtonA))
    {
        //�^�C�g���̃I�u�W�F�N�g������B
        NewGO<Title>(0, "title");
        //���g���폜����B
        DeleteGO(this);
    }
}

//�`�揈���B
void GameOver::Render(RenderContext& rc)
{
    m_spriteRender.Draw(rc);
}


