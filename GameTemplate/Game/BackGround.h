#pragma once

class BackGround: public IGameObject
{
    //�w�i�B
    public:
        BackGround();
        ~BackGround();

        //�`��֐��B
        void Render(RenderContext& rc);

        //���f�������_�\�B        
        ModelRender modelRender;
        //�����蔻��B
        PhysicsStaticObject physicsStaticObject;
};

