//=============================================================================
//
// 砂の重量 [weight.cpp]
// Author : 三橋錬
//
//=============================================================================
#include "weight.h"
#include "manager.h"
#include "renderer.h"
#include "keyboard.h"
#include "data.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CWeight::CWeight(OBJTYPE nPriority) : CScene(nPriority)
{
	for (int nCnt = 0; nCnt < WEIGHT_DIGITS; nCnt++)	m_apNumber[nCnt] = 0;
	m_nWeight = 0;
}

//=============================================================================
// デストラクタ
//=============================================================================
CWeight::~CWeight()
{

}

//=============================================================================
// ポリゴンの初期化処理
//=============================================================================
HRESULT CWeight::Init(void)
{
	for (int nCnt = 0; nCnt < WEIGHT_DIGITS; nCnt++)	m_apNumber[nCnt] = 0;
	m_nWeight = 0;

	return S_OK;
}

//=============================================================================
// ポリゴンの終了処理
//=============================================================================
void CWeight::Uninit(void)
{
	for (int nCnt = 0; nCnt < WEIGHT_DIGITS; nCnt++)
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
void CWeight::Update(void)
{
	if (CManager::GetData()->GetNowGame())
	{
		if (CManager::GetInputKeyboard()->GetPress(DIK_SPACE))
		{
			m_nWeight--;
		}
	}

	if (m_nWeight > MAX_WEIGHT)
	{
		m_nWeight = MAX_WEIGHT;
	}

	if (m_nWeight < 0)
	{
		m_nWeight = 0;
	}

	for (int nCnt = 0; nCnt < WEIGHT_DIGITS; nCnt++)
	{
		if (nCnt == 0)
		{
			m_apNumber[nCnt]->SetNumber(m_nWeight / (int)powf(10, WEIGHT_DIGITS - 1));
		}
		else if (nCnt == WEIGHT_DIGITS - 1)
		{
			m_apNumber[nCnt]->SetNumber(m_nWeight % 10);
		}
		else
		{
			m_apNumber[nCnt]->SetNumber(m_nWeight % (int)powf(10.0f, WEIGHT_DIGITS - (float)nCnt) / (int)powf(10.0f, WEIGHT_DIGITS - 1.0f - (float)nCnt));
		}
	}
}

//=============================================================================
// ポリゴンの描画処理
//=============================================================================
void CWeight::Draw(void)
{
	for (int nCnt = 0; nCnt < WEIGHT_DIGITS; nCnt++)
	{
		m_apNumber[nCnt]->Draw();
	}
}

void CWeight::SetWeight(int nScore)
{
	m_nWeight = nScore;
}

CWeight *CWeight::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CWeight* pWeight = new CWeight;

	if (pWeight != NULL)
	{
		pWeight->Init();
		pWeight->Set(pos, size);
	}
	return pWeight;
}

void CWeight::Set(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	m_pos = pos;
	m_size = size;

	for (int nCnt = 0; nCnt < WEIGHT_DIGITS; nCnt++)
	{
		m_apNumber[nCnt] = CNumber::Create(D3DXVECTOR3(pos.x + (size.x * nCnt) * 2.0f, pos.y, 0.0f), D3DXVECTOR3(size.x, size.y, 0.0f));
	}
}