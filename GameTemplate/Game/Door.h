#pragma once

class Player;

class Door : public IGameObject
{
public:
	Door();
	~Door();
	bool Start();
	void Update();
	void Move();
	void ReleasePhysicsObject();
	void Render(RenderContext& rc);

	Vector3 m_position;
	Vector3 m_firstPosition;	//最初のposition。

	PhysicsStaticObject m_physicsStaticObject;	//当たり判定。
	ModelRender m_doorModel;	//モデルレンダ―。

	Player* m_player;	//プレイヤー。
};

