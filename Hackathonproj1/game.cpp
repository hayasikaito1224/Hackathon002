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
#include "time.h"
#include "data.h"
#include "goalscore.h"
#include <random>

static const D3DXVECTOR3 BalanceSize = { 250.0f, 125.0f, 0.0f };//秤の大きさ
static const D3DXVECTOR3 BalancePos = { SCREEN_WIDTH/2, 550.0f, 0.0f };//秤の位置

//静的メンバ変数宣言
CBg		*CGame::m_pBg = nullptr;
CPlayer	*CGame::m_Player = nullptr;
CPolygon *CGame::m_Polygon = nullptr;
CWeight *CGame::m_Weight = nullptr;
CTime *CGame::m_Time = nullptr;
CGoalScore *CGame::m_GoalScore = nullptr;

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
	m_Time = nullptr;
	m_bPush = false;
	m_bEnd = false;
	m_GoalScore = nullptr;
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
	{//目標のスコアの生成
		std::random_device random;	// 非決定的な乱数生成器
		std::mt19937_64 mt(random());            // メルセンヌ・ツイスタの64ビット版、引数は初期シード
		std::uniform_real_distribution<> randTargetScore(10.0f, 16.0f);
		int nTargetScore = randTargetScore(mt);
		CData *pData = CManager::GetData();
		pData->SetTargetScore(nTargetScore * 100);

		pData->ReverseNowGame();
	}
	//背景の生成
	CBg::Create(CTexture::GameBg, CScene::OBJTYPE_BG, false);
	CPolygon::Create(BalancePos, BalanceSize, CTexture::Balance);

	//秤用数字の生成
	if (!m_Weight)
	{
		m_Weight = CWeight::Create(D3DXVECTOR3(525.0f, 575.0f, 0.0f), D3DXVECTOR3(25.0f, 45.0f, 0.0f));
	}

	//時間用数字の生成
	if (!m_Time)
	{
		m_Time = CTime::Create(D3DXVECTOR3((SCREEN_WIDTH / 2.0f) - 50.0f, 50.0f, 0.0f), D3DXVECTOR3(40.0f, 60.0f, 0.0f));
	}

	//目標重量用数字の生成
	if (!m_GoalScore)
	{
		m_GoalScore = CGoalScore::Create(D3DXVECTOR3(SCREEN_WIDTH - (40.0f * 8.0f), SCREEN_HEIGHT - (60.0f * 2.0f), 0.0f), D3DXVECTOR3(40.0f, 60.0f, 0.0f));
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

	if (m_Time != nullptr)
	{
		m_Time->Uninit();
		m_Time = nullptr;
	}

	if (m_GoalScore != nullptr)
	{
		m_GoalScore->Uninit();
		m_GoalScore = nullptr;
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

