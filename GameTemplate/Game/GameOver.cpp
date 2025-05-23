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
    //ゲームクリアの画像を読み込む。
    m_spriteRender.Init("Assets/sprite/GameOver.DDS", 1920.0f, 1080.0f);

    return true;
}

void GameOver::Update()
{
    //Aボタンが押されたら。
    if (g_pad[0]->IsTrigger(enButtonA))
    {
        //タイトルのオブジェクトをつくる。
        NewGO<Title>(0, "title");
        //自身を削除する。
        DeleteGO(this);
    }
}

//描画処理。
void GameOver::Render(RenderContext& rc)
{
    m_spriteRender.Draw(rc);
}


