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
//------------------------------------
//�}�N����`
//------------------------------------

//--------------------------
//�R���X�g���N�g
//--------------------------
CPlayer::CPlayer(OBJTYPE nPriority) : CScene2D(nPriority)
{
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
}



