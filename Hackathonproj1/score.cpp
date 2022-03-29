//=============================================================================
//
// �X�R�A [score.cpp]
// Author : �O���B
//
//=============================================================================
#include "score.h"
#include "manager.h"
#include "renderer.h"
#include "data.h"
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CScore::CScore(OBJTYPE nPriority) : CScene(nPriority)
{
	for (int nCnt = 0; nCnt < SCORE_DIGITS; nCnt++)	m_apNumber[nCnt] = 0;
	m_nScore = 0;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CScore::~CScore()
{

}

//=============================================================================
// �|���S���̏���������
//=============================================================================
HRESULT CScore::Init(void)
{
	for (int nCnt = 0; nCnt < SCORE_DIGITS; nCnt++)	m_apNumber[nCnt] = 0;
	m_nScore = 0;

	return S_OK;
}

//=============================================================================
// �|���S���̏I������
//=============================================================================
void CScore::Uninit(void)
{
	CManager::GetData()->SetScore(m_nScore);
	for (int nCnt = 0; nCnt < SCORE_DIGITS; nCnt++)
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
// �|���S���̍X�V����
//=============================================================================
void CScore::Update(void)
{
	m_nScore = CManager::GetData()->GetScore();

	if (m_nScore > MAX_SCORE)
	{
		m_nScore = MAX_SCORE;
	}

	for (int nCnt = 0; nCnt < SCORE_DIGITS; nCnt++)
	{
		if (nCnt == 0)
		{
			m_apNumber[nCnt]->SetNumber(m_nScore / (int)powf(10, SCORE_DIGITS - 1));
		}
		else if (nCnt == SCORE_DIGITS - 1)
		{
			m_apNumber[nCnt]->SetNumber(m_nScore % 10);
		}
		else
		{
			m_apNumber[nCnt]->SetNumber(m_nScore % (int)powf(10.0f, SCORE_DIGITS - (float)nCnt) / (int)powf(10.0f, SCORE_DIGITS - 1.0f - (float)nCnt));
		}
	}
}

//=============================================================================
// �|���S���̕`�揈��
//=============================================================================
void CScore::Draw(void)
{
	for (int nCnt = 0; nCnt < SCORE_DIGITS; nCnt++)
	{
		m_apNumber[nCnt]->Draw();
	}
}

void CScore::SetScore(int nScore)
{
	m_nScore = nScore;
}

CScore *CScore::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CScore* pScore = new CScore;

	if (pScore != NULL)
	{
		pScore->Init();
		pScore->Set(pos, size);
	}
	return pScore;
}

void CScore::Set(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	m_pos = pos;
	m_size = size;

	for (int nCnt = 0; nCnt < SCORE_DIGITS; nCnt++)
	{
		m_apNumber[nCnt] = CNumber::Create(D3DXVECTOR3(pos.x + (size.x * nCnt) * 2.0f, pos.y, 0.0f), D3DXVECTOR3(size.x, size.y, 0.0f));
	}
}