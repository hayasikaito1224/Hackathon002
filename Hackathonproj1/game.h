//--------------------------------------
//�^�C�g���̏���
//--------------------------------------
#ifndef _GAME_H
#define _GAME_H
#include "main.h"
#include "scene.h"
#define MAX_MAGICCOMMAND (3)
#define MAX_COMMAND (3)
#define MAX_SPAWNER (3)
#define PLAYER_CP (100)		//�}�i�̑���

//�O���錾
class CBg;
class CPlayer;
class CScene3D;
class CParticle;
class CPolygon;

class CGame
{
public:
	typedef enum
	{
		LEVEL_EASY=0,
		LEVEL_NORMAL,
		LEVEL_HARD,
		LEVEL_MAX
	}LEVEL;

	CGame();
	~CGame();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(LPD3DXMATRIX mtrix);

	static CPlayer *GetPlayer(void) { return m_Player; }
	static CModel_Spawner *GetModel(void) { return m_pModel; }
	static CPolygon		*GetCursol(void) { return m_Cursol; }
	static CParticle		*GetParticle(void) { return m_Particle; }
	static CGauge		*GetHPGauge() { return m_pHPGauge; }
	static CGauge		*GetMPGauge() { return m_pMPGauge; }
	static CGauge		*GetBossHPGauge() { return m_pBossHPGauge; }


private:
	static CGauge *m_pHPGauge;
	static CGauge *m_pMPGauge;
	static CGauge *m_pBossHPGauge;

	static std::vector<CPolygon*> m_pCStock;
	static CBg			*m_pBg;
	static CPlayer		*m_Player;
	static CModel_Spawner *m_pModel;
	static CPolygon		*m_Polygon;
	static CPolygon		*m_Cursol;
	static CParticle	*m_Particle;
	static int			m_nChancePoint;											//�`�����X�|�C���g
	static int			m_nChanceStock;
	bool m_bPush;
	bool m_bEnd;
	bool m_bGimmickUnlock;
	int m_nCntDelay;//�f�B���C�̃J�E���^
	int m_nGimmickNum;//�M�~�b�N�̃i���o�[
	float				m_fAlpha;
	bool				m_bNextMode;//��d�����h�~�ϐ�
	int					m_nTimer;//�J�E���^�[
	CScene3D			*m_pFlore;//��
};


#endif //_RESULT_H