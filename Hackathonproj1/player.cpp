//=============================================
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
#include "Polygon.h"
#include "directinput.h"
#include "weight.h"
//------------------------------------
//�}�N����`
//------------------------------------
#define PLAYER_POS_X (SCREEN_WIDTH/2.0f)
#define PLAYER_POS_Y (SCREEN_HEIGHT/2.0f)
#define PLAYER_SCALE_X (70.0)
#define PLAYER_SCALE_Y (70.0)
#define PLAYER_ANGLE_MAX (40.0)//�X���̍ő�l

//--------------------------
//�R���X�g���N�g
//--------------------------
CPlayer::CPlayer(OBJTYPE nPriority) : CScene(nPriority)
{
	m_pPlayer = nullptr;
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
	pPlayer = new CPlayer(OBJTYPE_PLAYER);
	pPlayer->Init();
	return pPlayer;
}
//---------------------------------------------
//������
//---------------------------------------------
HRESULT CPlayer::Init()
{
	//�|���S���̐���
	m_pPlayer = CScene2D::Create({ PLAYER_POS_X ,PLAYER_POS_Y,0.0f }, { PLAYER_SCALE_X ,PLAYER_SCALE_Y ,0.0f}, CTexture::Bag,OBJTYPE_PLAYER);
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

	//�X���鏈��
	Incline();
}
//-------------------------------------------
//�`�揈��
//-------------------------------------------
void CPlayer::Draw()
{
}
//-------------------------------------------
//�܂��X���鏈��
//-------------------------------------------
void CPlayer::Incline()
{
	//�X�y�[�X����������
	CInputKeyBoard *pKeyBoard = CManager::GetInputKeyboard();
	if (pKeyBoard->GetPress(DIK_SPACE) == true)
	{
		AddState(m_fMoveAngle);

	}
	else
	{
		DefState(m_fMoveAngle);
	}
	//�������炷
	m_fSandRemaining -= m_fMoveAngle / 100;
	CWeight *pWeight = CManager::GetGame()->GetWeight();
	pWeight->SetWeight(m_fSandRemaining*10);

	m_pPlayer->SetAngle(D3DXToRadian(m_fMoveAngle));
	m_pPlayer->Rotate({ PLAYER_POS_X ,PLAYER_POS_Y,0.0f }, { PLAYER_SCALE_X ,PLAYER_SCALE_Y ,0.0f });

}
//-------------------------------------------
//�X���p�x�̕��
//-------------------------------------------
void CPlayer::AddState(float & fAngle)
{
	fAngle -= 2.0f;
	if (fAngle <= -PLAYER_ANGLE_MAX)
	{
		fAngle = -PLAYER_ANGLE_MAX;
	}
}
//-------------------------------------------
//�X���p�x�̕��
//-------------------------------------------
void CPlayer::DefState(float & fAngle)
{
	fAngle += 2.0f;
	if (fAngle >= 0.0f)
	{
		fAngle = 0.0f;
	}
}
