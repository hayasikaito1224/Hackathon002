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
class CWeight;
class CTime;
class CGoalScore;
class CHide;
class CGame
{
public:

	CGame();
	~CGame();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void SetGameEnd(bool bGameEnd) { m_bGameEnd = bGameEnd; }
	static CPlayer *GetPlayer() { return m_Player; }
	static CWeight *GetWeight() { return m_Weight; }
	static CTime *GetTime()		{ return m_Time; }
	static CGoalScore *GetGoalScore() { return m_GoalScore; }

private:

	static CBg			*m_pBg;
	static CPlayer		*m_Player;
	static CPolygon		*m_Polygon;
	static CPolygon		*m_Sign;//看板のポリゴン

	static CHide		*m_Hide;//重量を隠すポリゴン
	static CWeight		*m_Weight;
	static CTime		*m_Time;
	static CGoalScore	*m_GoalScore;

	bool m_bPush;
	bool m_bGameEnd;
	float				m_fAlpha;
	bool				m_bNextMode;//二重押し防止変数
	int					m_nTimer;//カウンター
};


#endif //_GAME_H