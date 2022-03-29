//=============================================
//プレイヤーの処理
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
//マクロ定義
//------------------------------------

//--------------------------
//コンストラクト
//--------------------------
CPlayer::CPlayer(OBJTYPE nPriority) : CScene2D(nPriority)
{
}
//--------------------------
//デストラクト
//----------------------------
CPlayer::~CPlayer()
{

}
//----------------------------------------------
//インスタンス生成
//----------------------------------------------
CPlayer *CPlayer::Create()
{
	CPlayer *pPlayer = NULL;
	pPlayer = new CPlayer;
	pPlayer->Init();
	return pPlayer;
}
//---------------------------------------------
//初期化
//---------------------------------------------
HRESULT CPlayer::Init()
{
	return S_OK;
}
///-------------------------------------------
//破棄
//------------------------------------------
void CPlayer::Uninit()
{
	Release();
}
//-------------------------------------------
//更新
//-------------------------------------------
void CPlayer::Update()
{
	CXInput *pGamePad = CManager::GetXInput();
	CInputKeyBoard *pKeyBoard = CManager::GetInputKeyboard();
}
//-------------------------------------------
//描画処理
//-------------------------------------------
void CPlayer::Draw()
{



}
//-------------------------------------------
//袋を傾ける処理
//-------------------------------------------
void CPlayer::Incline()
{
}



