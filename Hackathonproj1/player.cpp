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
#include "data.h"

//�G�t�F�N�g
#include "SetEffect.h"
//------------------------------------
//�}�N����`
//------------------------------------
#define PLAYER_POS_X (SCREEN_WIDTH/2.0f)
#define PLAYER_POS_Y (SCREEN_HEIGHT/2.0f - 45)
#define PLAYER_SCALE_X (140.0)
#define PLAYER_SCALE_Y (140.0)
#define PLAYER_ANGLE_MAX (40.0)//�X���̍ő�l

//--------------------------
//�R���X�g���N�g
//--------------------------
CPlayer::CPlayer(OBJTYPE nPriority) : CScene(nPriority)
{
	m_pPlayer = nullptr;
	m_fSandRemaining = 300.0f;
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
	if (CManager::GetData()->GetNowGame())
	{
		CXInput *pGamePad = CManager::GetXInput();
		CInputKeyBoard *pKeyBoard = CManager::GetInputKeyboard();

		//�X���鏈��
		Incline();
	}
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

	CWeight *pWeight = CManager::GetGame()->GetWeight();

	if (pKeyBoard->GetPress(DIK_SPACE) == true)
	{
		AddState(m_fMoveAngle);

		if (pWeight->GetWeight() > 0)	//0�ȉ��Ŕ������Ȃ�
		{
			//�G�t�F�N�g�̔���
			CSetEffect::SetEffect(0, m_pPlayer->GetEffect(), {});	//���F��
			CSetEffect::SetEffect(1, m_pPlayer->GetEffect(), {});	//����(��)
			CSetEffect::SetEffect(2, m_pPlayer->GetEffect(), {});	//����(��)
		}

	}
	else
	{
		DefState(m_fMoveAngle);
	}
	//�������炷
	m_fSandRemaining -= abs(m_fMoveAngle) / 100;
	pWeight->SetWeight(m_fSandRemaining * 10);

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
