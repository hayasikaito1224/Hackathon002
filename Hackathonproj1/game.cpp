//--------------------------------------
//�Q�[����ʂ̏���
//--------------------------------------
#include "game.h"
#include "Renderer.h"//��ŏ���
#include "bg.h"
#include "texture.h"
#include "manager.h"
#include "keyboard.h"
#include "player.h"
#include "fade.h"
#include "time.h"
#include "Polygon.h"
#include "XInput.h"
#include "Particle.h"
#include "directinput.h"

#define PLAYER_LIFE (100)		//������
#define PLAYER_MP (100)		//�}�i�̑���
#define MAX_DELAY (30)//�f�B���C�̍ő�
//�ÓI�����o�ϐ��錾
CBg		*CGame::m_pBg = nullptr;
CPlayer	*CGame::m_Player = nullptr;
CModel_Spawner *CGame::m_pModel = nullptr;
CPolygon *CGame::m_Polygon = nullptr;
CPolygon *CGame::m_Cursol = nullptr;
CParticle   *CGame::m_Particle = nullptr;
CGauge   *CGame::m_pBossHPGauge = nullptr;
CGauge   *CGame::m_pHPGauge = nullptr;
CGauge   *CGame::m_pMPGauge = nullptr;

std::vector<CPolygon*>   CGame::m_pCStock = {};

int   CGame::m_nChancePoint = 0;
int   CGame::m_nChanceStock = 0;

static float s_texrotx = 0.0f;
static float s_texseax = 0.0f;
static int s_nTime = 0;
static bool s_bTime = false;

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CGame::CGame()
{
	m_pHPGauge = nullptr;
	m_pMPGauge = nullptr;
	m_pBossHPGauge = nullptr;
	m_pCStock.clear();
	m_Player = nullptr;
	m_pFlore = nullptr;
	m_pBg = nullptr;
	m_pModel = nullptr;
	m_Particle = nullptr;
	m_Polygon = nullptr;
	m_nCntDelay = 0;
	m_bPush = false;
	m_bEnd = false;
	m_bGimmickUnlock = false;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CGame::~CGame()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CGame::Init(void)
{


	//�v���C���[�̐���
	if (!m_Player)
	{
		m_Player = CPlayer::Create();
	}
	if (m_Particle == nullptr)
	{
		m_Particle = new CParticle;
	}

	//�ړI�\��
	CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2.0f, 40.0f, 0.0f),
		D3DXVECTOR3(210.0f, 20.0f, 0.0f), CTexture::TargetText);
	//������@
	CPolygon::Create(D3DXVECTOR3(140.0f, SCREEN_HEIGHT-130.0f, 0.0f),
		D3DXVECTOR3(140.0f, 90.0f, 0.0f), CTexture::Operation);

	m_fAlpha = 1.0f;
	m_bNextMode = false;
	m_nTimer = 0;
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CGame::Uninit(void)
{

	if (m_Player != nullptr)
	{
		m_Player->Uninit();
		m_Player = nullptr;
	}
	if (m_Cursol != nullptr)
	{
		m_Cursol->Uninit();
		m_Cursol = nullptr;
	}
	if (m_Polygon != nullptr)
	{
		m_Polygon->Uninit();
		m_Polygon = nullptr;
	}
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CGame::Update(void)
{
	//DirectInput�̃Q�[���p�b�h�̎擾
	CDirectInput *pGamePad = CManager::GetDirectInput();

	//�Q�[���������Ă�����

}

//--------------------------------------------
//�`��
//--------------------------------------------
void CGame::Draw(LPD3DXMATRIX mtrix)
{
}

