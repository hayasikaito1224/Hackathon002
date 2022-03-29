//=============================================================================
//
// 目標の重量 [goalscore.cpp]
// Author : 三橋錬
//
//=============================================================================
#include "goalscore.h"
#include "manager.h"
#include "renderer.h"
#include "data.h"
//=============================================================================
// コンストラクタ
//=============================================================================
CGoalScore::CGoalScore(OBJTYPE nPriority) : CScene(nPriority)
{
	for (int nCnt = 0; nCnt < GOAL_DIGITS; nCnt++)	m_apNumber[nCnt] = 0;
	m_nGoalScore = 0;

	m_nGoalScore = CManager::GetData()->GetTargetScore();
}

//=============================================================================
// デストラクタ
//=============================================================================
CGoalScore::~CGoalScore()
{

}

//=============================================================================
// ポリゴンの初期化処理
//=============================================================================
HRESULT CGoalScore::Init(void)
{
	for (int nCnt = 0; nCnt < GOAL_DIGITS; nCnt++)	m_apNumber[nCnt] = 0;

	return S_OK;
}

//=============================================================================
// ポリゴンの終了処理
//=============================================================================
void CGoalScore::Uninit(void)
{
	for (int nCnt = 0; nCnt < GOAL_DIGITS; nCnt++)
	{
		if (m_apNumber[nCnt] != NULL)
		{
			m_apNumber[nCnt]->Uninit();
			m_apNumber[nCnt] = NULL;
		}
	}
	Release();
}

//=============================================================================
// ポリゴンの更新処理
//=============================================================================
void CGoalScore::Update(void)
{
	for (int nCnt = 0; nCnt < GOAL_DIGITS; nCnt++)
	{
		if (nCnt == 0)
		{
			m_apNumber[nCnt]->SetNumber(m_nGoalScore / (int)powf(10, GOAL_DIGITS - 1));
		}
		else if (nCnt == GOAL_DIGITS - 1)
		{
			m_apNumber[nCnt]->SetNumber(m_nGoalScore % 10);
		}
		else
		{
			m_apNumber[nCnt]->SetNumber(m_nGoalScore % (int)powf(10.0f, GOAL_DIGITS - (float)nCnt) / (int)powf(10.0f, GOAL_DIGITS - 1.0f - (float)nCnt));
		}
	}
}

//=============================================================================
// ポリゴンの描画処理
//=============================================================================
void CGoalScore::Draw(void)
{
	for (int nCnt = 0; nCnt < GOAL_DIGITS; nCnt++)
	{
		m_apNumber[nCnt]->Draw();
	}
}

void CGoalScore::SetScore(int nScore)
{
	m_nGoalScore = nScore;
}

CGoalScore *CGoalScore::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CGoalScore* pScore = new CGoalScore;

	if (pScore != NULL)
	{
		pScore->Init();
		pScore->Set(pos, size);
	}
	return pScore;
}

void CGoalScore::Set(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	m_pos = pos;
	m_size = size;

	for (int nCnt = 0; nCnt < GOAL_DIGITS; nCnt++)
	{
		m_apNumber[nCnt] = CNumber::Create(D3DXVECTOR3(pos.x + (size.x * nCnt) * 2.0f, pos.y, 0.0f), D3DXVECTOR3(size.x, size.y, 0.0f));
	}
}