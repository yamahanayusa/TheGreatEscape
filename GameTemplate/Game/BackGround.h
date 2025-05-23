#pragma once

class BackGround: public IGameObject
{
    //背景。
    public:
        BackGround();
        ~BackGround();

        //描画関数。
        void Render(RenderContext& rc);

        //モデルレンダ―。        
        ModelRender modelRender;
        //当たり判定。
        PhysicsStaticObject physicsStaticObject;
};

