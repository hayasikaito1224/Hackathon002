//--------------------------------------
//タイトルの処理
//--------------------------------------
#ifndef _GAME_H
#define _GAME_H
#include "main.h"
#include "scene.h"

//前方宣言
class CBg;
class CPlayer;
class CPolygon;
class CScore;

class CGame
{
public:

	CGame();
	~CGame();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();

	static CPlayer *GetPlayer() { return m_Player; }
	static CScore *GetScore() { return m_Score; }

private:

	static CBg			*m_pBg;
	static CPlayer		*m_Player;
	static CPolygon		*m_Polygon;
	static CScore		*m_Score;
	bool m_bPush;
	bool m_bEnd;
	float				m_fAlpha;
	bool				m_bNextMode;//二重押し防止変数
	int					m_nTimer;//カウンター
};


#endif //_GAME_H