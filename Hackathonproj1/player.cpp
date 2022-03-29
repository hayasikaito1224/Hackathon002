//=============================================-
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
#define PLAYER_POS_X (SCREEN_WIDTH/2.0f)
#define PLAYER_POS_Y (SCREEN_HEIGHT/2.0f)
#define PLAYER_SCALE_X (70.0)
#define PLAYER_SCALE_Y (70.0)

//--------------------------
//コンストラクト
//--------------------------
CPlayer::CPlayer(OBJTYPE nPriority) : CScene(nPriority)
{
	m_pPlayer = nullptr;
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
	pPlayer = new CPlayer(OBJTYPE_PLAYER);
	pPlayer->Init();
	return pPlayer;
}
//---------------------------------------------
//初期化
//---------------------------------------------
HRESULT CPlayer::Init()
{
	//ポリゴンの生成
	m_pPlayer = CScene2D::Create({ PLAYER_POS_X ,PLAYER_POS_Y,0.0f }, { PLAYER_SCALE_X ,PLAYER_SCALE_Y ,0.0f}, CTexture::Test);
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

	//傾ける処理
	Incline();
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
	//スペースを押したら
	CInputKeyBoard *pKeyBoard = CManager::GetInputKeyboard();
	if (pKeyBoard->GetPress(DIK_SPACE) == true)
	{
		m_pPlayer->SetAngle(D3DXToRadian(-40.0f));
		m_pPlayer->Rotate({ PLAYER_POS_X ,PLAYER_POS_Y,0.0f }, { PLAYER_SCALE_X ,PLAYER_SCALE_Y ,0.0f });

	}
}
