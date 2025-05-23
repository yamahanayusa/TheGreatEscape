#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround() 
{
	modelRender.Init("Assets/modelData/ste.tkm");
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}

BackGround::~BackGround()
{

}

void BackGround::Render(RenderContext& renderContext)
{
	modelRender.Draw(renderContext);
}
