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
#include "Polygon.h"
#include "directinput.h"
//------------------------------------
//�}�N����`
//------------------------------------
#define PLAYER_POS_X (SCREEN_WIDTH/2.0f)
#define PLAYER_POS_Y (SCREEN_HEIGHT/2.0f)
#define PLAYER_SCALE_X (70.0)
#define PLAYER_SCALE_Y (70.0)

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
	m_pPlayer = CScene2D::Create({ PLAYER_POS_X ,PLAYER_POS_Y,0.0f }, { PLAYER_SCALE_X ,PLAYER_SCALE_Y ,0.0f}, CTexture::Test);
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
		m_pPlayer->SetAngle(D3DXToRadian(-40.0f));
		m_pPlayer->Rotate({ PLAYER_POS_X ,PLAYER_POS_Y,0.0f }, { PLAYER_SCALE_X ,PLAYER_SCALE_Y ,0.0f });

	}
}
