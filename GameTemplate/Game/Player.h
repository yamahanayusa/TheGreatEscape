#pragma once

class Enemy1;
class Hp;

class Player : public IGameObject
{
public:
	Player();
	~Player();
	//アタック。
	void Atk();
	//初期設定
	bool Start();
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& rc);
	//移動処理。
	void Move();
	//回転処理。
	void Rotation();
	//ステート管理。
	void ManageState();
	//アニメーションの再生。
	void PlayAnimation();

	Enemy1* m_enemy1 = nullptr;
	Hp* m_hp = nullptr;

	ModelRender m_modelRender;	//モデルレンダ―。
	CharacterController m_characterController;  //キャラクターコントローラー。

	Vector3 m_position = Vector3(0.0f, 0.0f, 10.0f);			//座標。
	Vector3 m_moveSpeed;		//移動速度。
	Quaternion m_rotation;  //クォータニオン。
	Vector3	m_forward = Vector3::AxisZ; //ライト。

	int m_playerState = 0;	//プレイヤーのステート(状態)を表す変数。
	int m_coinCount = 0;	//集めた☆の数をカウントする。
	int m_invincibleTime = 120;	//無敵時間。
	int m_hpCount = 0;		//hpが減った数をカウントする。

	enum EnAnimationClip {		//アニメーション。
		enAnimationClip_Walk,
		enAnimationClip_Idle,
		enAnimationClip_Num,
	};
	AnimationClip m_animationClips[enAnimationClip_Num];		//アニメーションクリップ。
	
};

