//=============================================-
//�v���C���[�̏���
//=============================================
#include "main.h"
#include "manager.h"
#include "Renderer.h"
#include "player.h"
#include "keyboard.h"
#include "game.h"
#include "fade.h"
#include "XInput.h"
#include "sound.h"
#include "keyboard.h"
#include "effect.h"
#include "Polygon.h"
#include "Particle.h"
#include "directinput.h"
//------------------------------------
//�}�N����`
//------------------------------------
#define MAX_DELAY_TIME (30)
#define MAX_MAGIC_SHOT_TIME (2.0)
#define MAX_PLAYER_JUMP (1)//�ő�̃W�����v��
#define MAX_PLAYER_PARTS (16)
#define PLAYER_SIZE (20.0)
#define SWORDEFFECT_LONG (16)
#define PLAYER_RANGE (700.0)		//�v���C���[�ƓG�̋߂���}��͈�
#define PLAYER_ROCKON_SIZE (5.0)	//���b�N�I���摜�̃T�C�Y
#define PLAYER_POWER (5)			//�U����
#define PLAYER_HIT_MAXTIME (50)		//���G����̎���
#define PLAYER_DODGE_TIME (20.0f)		//����̎���
#define PLAYER_DODGE_SPEED (12.0f)		//����̑��x
#define PLAYER_ATTACK_SPEED (15.0f)		//�U���̈ړ����x
#define PLAYER_ADDCP (7)		//��������CP

//--------------------------
//�R���X�g���N�g
//--------------------------
CPlayer::CPlayer(OBJTYPE nPriority) : CScene(nPriority)
{
	memset(m_pMotion, NULL, sizeof(m_pMotion));
	memset(m_pModel, NULL, sizeof(m_pModel));
	memset(m_pSwordEffect, NULL, sizeof(m_pSwordEffect));
	m_fMagicShotDelayMax = MAX_MAGIC_SHOT_TIME;
	m_bAttack = false;
	m_bAttackNext = true;
	m_nMaxDelatTime = MAX_DELAY_TIME;
	m_bDelay = false;
	m_Magic.m_bRetryMagic = false;
	m_pRockOnPolygon = nullptr;
	m_nCommandType = 0;
	m_nMagicCommandType = 0;
	m_bDraw = true;
	m_bHit = false;
	m_bHitStop = false;
	m_State = STATE_NOWN;
	m_bDeth = false;
	m_bLockOn = false;
	m_bDodge = false;
	m_bBeginDodge = false;
	m_bEndDodge = false;
	m_fDodgeAddSpeed = 1.0f;
	m_fDodgeTimer = 0.0f;
	m_fDodgerot = 0.0f;
}
//--------------------------
//�f�X�g���N�g
//----------------------------
CPlayer::~CPlayer()
{

}
//----------------------------------------------
//�C���X�^���X����
//----------------------------------------------
CPlayer *CPlayer::Create()
{
	CPlayer *pPlayer = NULL;
	pPlayer = new CPlayer;
	pPlayer->Init();
	return pPlayer;
}
//---------------------------------------------
//������
//---------------------------------------------
HRESULT CPlayer::Init()
{
	return S_OK;
}
///-------------------------------------------
//�j��
//------------------------------------------
void CPlayer::Uninit()
{
	Release();
}
//-------------------------------------------
//�X�V
//-------------------------------------------
void CPlayer::Update()
{
	CXInput *pGamePad = CManager::GetXInput();
	CInputKeyBoard *pKeyBoard = CManager::GetInputKeyboard();
	if (m_bDeth == false)
	{
		//�v���C���[�̈ړ�����
	}
}
//-------------------------------------------
//�`�揈��
//-------------------------------------------
void CPlayer::Draw()
{


	//�O��̈ʒu���̕ۑ�
	m_lastpos = m_pos;

}
void CPlayer::Drawtext()
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	char str[3000];
	int nNum = 0;

	nNum = sprintf(&str[0], "\n\n �Ǐ�� \n");

	nNum += sprintf(&str[nNum], " [modelPos] X%.2f,Y%.2f,Z%.2f \n", m_pos.x, m_pos.y, m_pos.z);
	nNum += sprintf(&str[nNum], " [modelPos] X%.2f,Y%.2f,Z%.2f \n", m_lastpos.x, m_lastpos.y, m_lastpos.z);

	LPD3DXFONT pFont = CManager::GetRenderer()->GetFont();
	// �e�L�X�g�`��
	pFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));

}


