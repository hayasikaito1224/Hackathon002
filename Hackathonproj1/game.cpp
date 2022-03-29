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
#include "directinput.h"
#include "weight.h"
#include "time.h"

static const D3DXVECTOR3 BalanceSize = { 250.0f, 125.0f, 0.0f };//���̑傫��
static const D3DXVECTOR3 BalancePos = { SCREEN_WIDTH/2, 550.0f, 0.0f };//���̈ʒu

//�ÓI�����o�ϐ��錾
CBg		*CGame::m_pBg = nullptr;
CPlayer	*CGame::m_Player = nullptr;
CPolygon *CGame::m_Polygon = nullptr;
CWeight *CGame::m_Weight = nullptr;
CTime *CGame::m_Time = nullptr;

static float s_texrotx = 0.0f;
static float s_texseax = 0.0f;
static int s_nTime = 0;
static bool s_bTime = false;

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CGame::CGame()
{
	m_Player = nullptr;
	m_pBg = nullptr;
	m_Polygon = nullptr;
	m_Weight = nullptr;
	m_Time = nullptr;
	m_bPush = false;
	m_bEnd = false;
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
HRESULT CGame::Init()
{

	//�w�i�̐���
	CBg::Create(CTexture::GameBg, CScene::OBJTYPE_BG, false);
	CPolygon::Create(BalancePos, BalanceSize, CTexture::Balance);

	//���p�����̐���
	if (!m_Weight)
	{
		m_Weight = CWeight::Create(D3DXVECTOR3(525.0f, 575.0f, 0.0f), D3DXVECTOR3(25.0f, 45.0f, 0.0f));
	}

	//���ԗp�����̐���
	if (!m_Time)
	{
		m_Time = CTime::Create(D3DXVECTOR3((SCREEN_WIDTH / 2) - 50, 50.0f, 0.0f), D3DXVECTOR3(40.0f, 60.0f, 0.0f));
	}

	//�v���C���[�̐���
	if (!m_Player)
	{
		m_Player = CPlayer::Create();
	}

	m_fAlpha = 1.0f;
	m_bNextMode = false;
	m_nTimer = 0;
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CGame::Uninit()
{

	if (m_Player != nullptr)
	{
		m_Player->Uninit();
		m_Player = nullptr;
	}

	if (m_Polygon != nullptr)
	{
		m_Polygon->Uninit();
		m_Polygon = nullptr;
	}

	if (m_Weight != nullptr)
	{
		m_Weight->Uninit();
		m_Weight = nullptr;
	}

	if (m_Time != nullptr)
	{
		m_Time->Uninit();
		m_Time = nullptr;
	}
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CGame::Update()
{
	//DirectInput�̃Q�[���p�b�h�̎擾

	//�Q�[���������Ă�����

}

//--------------------------------------------
//�`��
//--------------------------------------------
void CGame::Draw()
{

}

