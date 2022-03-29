//--------------------------------------
//�^�C�g���̏���
//--------------------------------------
#ifndef _GAME_H
#define _GAME_H
#include "main.h"
#include "scene.h"

//�O���錾
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
	static CPolygon		*m_Sign;//�Ŕ̃|���S��

	static CHide		*m_Hide;//�d�ʂ��B���|���S��
	static CWeight		*m_Weight;
	static CTime		*m_Time;
	static CGoalScore	*m_GoalScore;

	bool m_bPush;
	bool m_bGameEnd;
	float				m_fAlpha;
	bool				m_bNextMode;//��d�����h�~�ϐ�
	int					m_nTimer;//�J�E���^�[
};


#endif //_GAME_H