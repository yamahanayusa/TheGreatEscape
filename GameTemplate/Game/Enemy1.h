#pragma once

class Player;
class Game;
class Enemy1:public IGameObject
{
public:
	Enemy1();
	~Enemy1();
	void Update();
	void Rotation();
	//描画処理。
	void Render(RenderContext& rc);
	//アニメーションの再生。
	void PlayAnimation();
	
	//移動処理。
	void Move();
	

	enum EnAnimationClip {		//アニメーション。
		enAnimationClip_Walk,
		enAnimationClip_Num,
	};

	Vector3		m_position = Vector3(300.0f,0.0f,0.0f);		//座標。
	Vector3		m_firstPosition;	//最初の座標。
	Vector3		m_moveSpeed;
	Vector3     m_EPvector;	//敵からプレイヤーに向かうベクトル。
	//Vector3     m_rootPos[7];
	//int m_nowPosNum = 0;
	//int m_nextPosNum = 1;

	ModelRender m_modelRender;
	CharacterController m_characterController;  //キャラクターコントローラー。
	AnimationClip m_animationClips[enAnimationClip_Num];
	Quaternion m_rot;
	Player* m_player;
	Game* m_game;

	//最初の地点。
	//int m_start = 0;
	//最終の地点。
	//int m_rast = 6;
};

