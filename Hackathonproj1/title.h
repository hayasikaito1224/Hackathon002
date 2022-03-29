//--------------------------------------
//�^�C�g���̏���
//--------------------------------------
#ifndef _TITLE_H
#define _TITLE_H
#include "main.h"
#include "scene.h"
#define MAX_TITLE_POLYGON (3)
//�O���錾
class CBg;
class CPolygon;
class CSound;
class CTitle
{
public:
	typedef enum
	{
		GAME_START=0,
		OPERATION,
		MAX,
	}TYPE;
	CTitle();
	~CTitle();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void NextMode(bool bNextMode) { m_bNextMode = bNextMode; }

private:
	CPolygon			*m_Polygon[3];
	int					m_nSelectType;//�I�������^�C�v
	int					m_nCount;//�����_�ŗp�̃J�E���g
	int					m_nAlpha;//�����̃A���t�@�l
	bool				m_bNextMode;//���̃��[�h�ɍs�����߂�
	bool				m_bOpra;//�`���[�g���A��UI��I�����Ă��邩
	bool				m_bAlpha;//�����̃A���t�@�l���グ�邩�����邩
};


#endif //_TITLE_H