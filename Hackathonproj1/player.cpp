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
#include "weight.h"
//------------------------------------
//マクロ定義
//------------------------------------
#define PLAYER_POS_X (SCREEN_WIDTH/2.0f)
#define PLAYER_POS_Y (SCREEN_HEIGHT/2.0f)
#define PLAYER_SCALE_X (70.0)
#define PLAYER_SCALE_Y (70.0)
#define PLAYER_ANGLE_MAX (40.0)//傾きの最大値

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
	m_pPlayer = CScene2D::Create({ PLAYER_POS_X ,PLAYER_POS_Y,0.0f }, { PLAYER_SCALE_X ,PLAYER_SCALE_Y ,0.0f}, CTexture::Bag,OBJTYPE_PLAYER);
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
		AddState(m_fMoveAngle);

	}
	else
	{
		DefState(m_fMoveAngle);
	}
	//砂を減らす
	m_fSandRemaining -= m_fMoveAngle / 100;
	CWeight *pWeight = CManager::GetGame()->GetWeight();
	pWeight->SetWeight(m_fSandRemaining*10);

	m_pPlayer->SetAngle(D3DXToRadian(m_fMoveAngle));
	m_pPlayer->Rotate({ PLAYER_POS_X ,PLAYER_POS_Y,0.0f }, { PLAYER_SCALE_X ,PLAYER_SCALE_Y ,0.0f });

}
//-------------------------------------------
//傾き角度の補間
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
//傾き角度の補間
//-------------------------------------------
void CPlayer::DefState(float & fAngle)
{
	fAngle += 2.0f;
	if (fAngle >= 0.0f)
	{
		fAngle = 0.0f;
	}
}
