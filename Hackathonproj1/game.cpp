//--------------------------------------
//ゲーム画面の処理
//--------------------------------------
#include "game.h"
#include "Renderer.h"//後で消す
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

static const D3DXVECTOR3 BalanceSize = { 250.0f,150.0f,0.0f };//秤の大きさ
static const D3DXVECTOR3 BalancePos = { SCREEN_WIDTH/2,550.0f,0.0f };//秤の位置

//静的メンバ変数宣言
CBg		*CGame::m_pBg = nullptr;
CPlayer	*CGame::m_Player = nullptr;
CPolygon *CGame::m_Polygon = nullptr;
CWeight *CGame::m_Weight = nullptr;

static float s_texrotx = 0.0f;
static float s_texseax = 0.0f;
static int s_nTime = 0;
static bool s_bTime = false;

//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CGame::CGame()
{
	m_Player = nullptr;
	m_pBg = nullptr;
	m_Polygon = nullptr;
	m_Weight = nullptr;
	m_bPush = false;
	m_bEnd = false;
}
//--------------------------------------------
//デストラクタ
//--------------------------------------------
CGame::~CGame()
{
}
//--------------------------------------------
//初期化
//--------------------------------------------
HRESULT CGame::Init()
{

	//背景の生成
	CBg::Create(CTexture::GameBg, CScene::OBJTYPE_BG, false);
	CPolygon::Create(BalancePos, BalanceSize, CTexture::Balance);
	//プレイヤーの生成
	if (!m_Weight)
	{
		m_Weight = CWeight::Create(D3DXVECTOR3(50.0f, 50.0f, 50.0f), D3DXVECTOR3(30.0f, 50.0f, 50.0f));
	}
	//プレイヤーの生成
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
//終了
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
}
//--------------------------------------------
//更新
//--------------------------------------------
void CGame::Update()
{
	//DirectInputのゲームパッドの取得

	//ゲームが続いていたら

}

//--------------------------------------------
//描画
//--------------------------------------------
void CGame::Draw()
{
}

