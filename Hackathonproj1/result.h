//--------------------------------------
//タイトルの処理
//--------------------------------------
#ifndef _RESULT_H
#define _RESULT_H
#include "main.h"
#include "scene.h"
#define MAX_RESULT (4)
//前方宣言
class CBg;
class CPolygon;
class CWeight;
class CGoalScore;
class CScore;
class CRank;

class CResult
{
public:
	typedef enum
	{
		GAME_RETRY = 0,
		TITLE,
		MAX,
	}TYPE;

	CResult();
	~CResult();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void NextMode(bool bNextMode) { m_bNextMode = bNextMode; }

private:
	CPolygon			*pPolygon[MAX_RESULT];
	CPolygon			*m_Cursol;

	static CScore		*m_pScore;
	static CBg			*m_pBg;
	static CWeight		*m_Weight;
	static CGoalScore	*m_GoalScore;
	static CRank		*m_Rank;

	bool				m_bNextMode;//次のモードに行くための
	int					m_nSelectType;

};


#endif //_RESULT_H