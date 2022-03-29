//=============================================-
//プレイヤーの処理
//=============================================
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "scene2D.h"
//------------------------------------
//マクロ定義
//------------------------------------
#define PLAYER_POS_X (0.0)
#define PLAYER_POS_Y (0.0)
#define PLAYER_POS_Z (0.0)
#define PLAYER_FALL (-100.0)//落下判定に入るまでの位置

class CPlayer : public CScene2D
{
public:
	CPlayer(OBJTYPE nPriority = CScene::OBJTYPE_PLAYER);
	~CPlayer();
	//静的メンバー関数
	static CPlayer *Create();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void Incline();//袋を傾ける処理

private:
	D3DXVECTOR3 m_pos; //位置
	bool m_bGameStop;
};


#endif // !_PLAYER_H_
