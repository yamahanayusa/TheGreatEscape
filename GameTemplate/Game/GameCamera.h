#pragma once

//ばねカメラを使用したい場合は、SpringCameraをインクルードする。
#include "camera/SpringCamera.h"

class Player;

//ゲーム中のカメラを制御する。
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();
	
	Vector3 m_toCameraPos = Vector3::One;	//注視点から視点に向かうベクトル。
	SpringCamera m_springCamera;  //ばねカメラ。

	Player* m_player = nullptr;	//プレイヤー。
};

