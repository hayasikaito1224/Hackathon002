//=============================================================================
//
// 残り時間 [time.cpp]
// Author : 三橋錬
//
//=============================================================================
#include "time.h"
#include "manager.h"
#include "renderer.h"
#include "keyboard.h"
#include "data.h"
#include "fade.h"
#include "game.h"
#include "player.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CTime::CTime(OBJTYPE nPriority) : CScene(nPriority)
{
	for (int nCnt = 0; nCnt < TIME_DIGITS; nCnt++)	m_apNumber[nCnt] = 0;
	m_nTime = 10;
	m_nCommaTime = 0;
	m_bNextMode = false;
}

//=============================================================================
// デストラクタ
//=============================================================================
CTime::~CTime()
{

}

//=============================================================================
// ポリゴンの初期化処理
//=============================================================================
HRESULT CTime::Init(void)
{
	for (int nCnt = 0; nCnt < TIME_DIGITS; nCnt++)	m_apNumber[nCnt] = 0;
	m_nTime = 10;
	m_nCommaTime = 0;

	return S_OK;
}

//=============================================================================
// ポリゴンの終了処理
//=============================================================================
void CTime::Uninit(void)
{
	for (int nCnt = 0; nCnt < TIME_DIGITS; nCnt++)
	{
		if (m_apNumber[nCnt] != NULL)
		{
			m_apNumber[nCnt]->Uninit();
			m_apNumber[nCnt] = NULL;
		}
	}
}

//=============================================================================
// ポリゴンの更新処理
//=============================================================================
void CTime::Update(void)
{
	CData *pData = CManager::GetData();
	if (CManager::GetData()->GetNowGame())
	{
		m_nCommaTime++;

		if (m_nCommaTime >= 60)
		{
			m_nTime--;
			m_nCommaTime = 0;
		}
	}

	if (m_nTime > MAX_TIME)
	{
		m_nTime = MAX_TIME;
	}

	if (m_nTime <= 0)
	{
		m_nTime = 0;
		//スコアをセット
		pData->SetScore(abs(abs(pData->GetTargetScore()) - abs(CManager::GetGame()->GetPlayer()->GetSandRemaining() * 10.0f)));
	}

	for (int nCnt = 0; nCnt < TIME_DIGITS; nCnt++)
	{
		if (nCnt == 0)
		{
			m_apNumber[nCnt]->SetNumber(m_nTime / (int)powf(10, TIME_DIGITS - 1));
		}
		else if (nCnt == TIME_DIGITS - 1)
		{
			m_apNumber[nCnt]->SetNumber(m_nTime % 10);
		}
		else
		{
			m_apNumber[nCnt]->SetNumber(m_nTime % (int)powf(10.0f, TIME_DIGITS - (float)nCnt) / (int)powf(10.0f, TIME_DIGITS - 1.0f - (float)nCnt));
		}
	}
}

//=============================================================================
// ポリゴンの描画処理
//=============================================================================
void CTime::Draw(void)
{
	for (int nCnt = 0; nCnt < TIME_DIGITS; nCnt++)
	{
		m_apNumber[nCnt]->Draw();
	}
}

void CTime::SetTime(int nScore)
{
	m_nTime = nScore;
}

CTime *CTime::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CTime* pWeight = new CTime;

	if (pWeight != NULL)
	{
		pWeight->Init();
		pWeight->Set(pos, size);
	}
	return pWeight;
}

void CTime::Set(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	m_pos = pos;
	m_size = size;

	for (int nCnt = 0; nCnt < TIME_DIGITS; nCnt++)
	{
		m_apNumber[nCnt] = CNumber::Create(D3DXVECTOR3(pos.x + (size.x * nCnt) * 2.0f, pos.y, 0.0f), D3DXVECTOR3(size.x, size.y, 0.0f));
	}
}