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
	static CWeight *GetWeight() { return m_Weight; }

private:

	static CBg			*m_pBg;
	static CPlayer		*m_Player;
	static CPolygon		*m_Polygon;
	static CWeight		*m_Weight;
	bool m_bPush;
	bool m_bEnd;
	float				m_fAlpha;
	bool				m_bNextMode;//��d�����h�~�ϐ�
	int					m_nTimer;//�J�E���^�[
};


#endif //_GAME_H