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
#include "hide.h"
static const D3DXVECTOR3 BalanceSize = { 250.0f, 125.0f, 0.0f };//秤の大きさ
static const D3DXVECTOR3 SignSize = { 230.0f, 180.0f, 0.0f };//看板の大きさ

static const D3DXVECTOR3 BalancePos = { SCREEN_WIDTH/2, 550.0f, 0.0f };//秤の位置

//静的メンバ変数宣言
CBg		*CGame::m_pBg = nullptr;
CPlayer	*CGame::m_Player = nullptr;
CPolygon *CGame::m_Polygon = nullptr;
CWeight *CGame::m_Weight = nullptr;
CTime *CGame::m_Time = nullptr;
CGoalScore *CGame::m_GoalScore = nullptr;
CHide *CGame::m_Hide = nullptr;
CPolygon *CGame::m_Sign = nullptr;

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
	m_bGameEnd = false;
	m_GoalScore = nullptr;
	m_Hide = nullptr;
	m_Sign = nullptr;
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
		m_GoalScore = CGoalScore::Create(D3DXVECTOR3(SCREEN_WIDTH - (30.0f * 11.0f), SCREEN_HEIGHT - (50.0f * 3.0f), 0.0f), D3DXVECTOR3(30.0f, 50.0f, 0.0f));
	}

	//プレイヤーの生成
	if (!m_Player)
	{
		m_Player = CPlayer::Create();
	}

	//重量を隠す用のポリゴンの生成
	if (!m_Hide)
	{
		m_Hide = CHide::Create();
	}
	//看板
	if (!m_Sign)
	{
		m_Sign = CPolygon::Create({ SCREEN_WIDTH - 200.0f,SCREEN_HEIGHT - 120.0f,0.0f }, SignSize, CTexture::SignBoard);
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

	if (m_Sign != nullptr)
	{
		m_Sign->Uninit();
		m_Sign = nullptr;
	}

	if (m_Weight != nullptr)
	{
		m_Weight->Uninit();
		m_Weight = nullptr;
	}

	if (m_Hide != nullptr)
	{
		m_Hide->Uninit();
		m_Hide = nullptr;
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
	if (m_Hide)
	{
		m_Hide->Update();
	}
	//タイムが半分を切ったら
	{
		int nTime = m_Time->GetTimet();
		if (nTime <= 5&& nTime > 0)
		{
			if (m_Hide)
			{
				//ポリゴンが上がる設定にする
				m_Hide->IsUp(true);
			}
		}
		if (nTime <= 0)
		{
			if (m_Hide)
			{
				//ポリゴンが上がる設定にする
				m_Hide->IsUp(false);
				m_Hide->IsDown(true);
				//重量を隠す画像が元の位置に戻ったらゲーム終了
				if (m_Hide->GetPosBase())
				{
					m_bGameEnd = true;
				}
			}
		}
	}
	//ゲームの終了判定がオンなら
	if (m_bGameEnd)
	{
		if (m_bNextMode == false)
		{
			//CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_ENTER);
			//CManager::GetSound()->ControllVoice(CSound::SOUND_LABEL_SE_ENTER, 0.6f);

			//リザルトモードへ行く
			CFade::SetFade(CManager::MODE_RESULT);

			//二回以上通らないようにする
			m_bNextMode = true;
		}
	}
}

//--------------------------------------------
//描画
//--------------------------------------------
void CGame::Draw()
{

}

