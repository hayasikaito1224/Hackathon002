//=============================================-
//プレイヤーの処理
//=============================================
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "scene2D.h"
//------------------------------------
//マクロ定義
//------------------------------------

class CPlayer : public CScene
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
	CScene2D *m_pPlayer;//砂袋
	bool m_bGameStop;
};


#endif // !_PLAYER_H_
