//=============================================================================
//
// �����L���O [rank.cpp]
// Author : �O���B
//
//=============================================================================
#include "rank.h"
#include "manager.h"
#include "renderer.h"
#include "data.h"
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CRank::CRank(OBJTYPE nPriority) : CScene(nPriority)
{
	
	for (int nCnt = 0; nCnt < 5; nCnt++)
	{
		for (int nCnt2 = 0; nCnt2 < RANK_DIGITS; nCnt2++)	m_apNumber[nCnt][nCnt2] = 0;
		m_nRank[nCnt] = 0;
	}
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CRank::~CRank()
{

}

//=============================================================================
// �|���S���̏���������
//=============================================================================
HRESULT CRank::Init(void)
{
	for (int nCnt = 0; nCnt < 5; nCnt++)
	{
		for (int nCnt2 = 0; nCnt2 < RANK_DIGITS; nCnt2++)	m_apNumber[nCnt][nCnt2] = 0;
		m_nRank[nCnt] = 0;
	}



	return S_OK;
}

//=============================================================================
// �|���S���̏I������
//=============================================================================
void CRank::Uninit(void)
{
	for (int nCnt = 0; nCnt < 5; nCnt++)
	{
		for (int nCnt2 = 0; nCnt2 < RANK_DIGITS; nCnt2++)
		{
			if (m_apNumber[nCnt][nCnt2] != NULL)
			{
				m_apNumber[nCnt][nCnt2]->Uninit();
				m_apNumber[nCnt][nCnt2] = NULL;
			}
		}
	}

	Release();
}

//=============================================================================
// �|���S���̍X�V����
//=============================================================================
void CRank::Update(void)
{

}

//=============================================================================
// �|���S���̕`�揈��
//=============================================================================
void CRank::Draw(void)
{
	for (int nCnt = 0; nCnt < 5; nCnt++)
	{
		for (int nCnt2 = 0; nCnt2 < RANK_DIGITS; nCnt2++)
		{
			m_apNumber[nCnt][nCnt2]->Draw();
		}
	}
}

void CRank::SetRank(int num, int nRank)
{
	m_nRank[num] = nRank;
}

CRank *CRank::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CRank* pRank = new CRank;

	if (pRank != NULL)
	{
		pRank->Init();
		pRank->Set(pos, size);
	}
	return pRank;
}

void CRank::Set(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	m_pos = pos;
	m_size = size;

	for (int nCnt = 0; nCnt < 5; nCnt++)
	{
		m_nRank[nCnt] = 0;

		for (int nCnt2 = 0; nCnt2 < RANK_DIGITS; nCnt2++)
		{
			m_apNumber[nCnt][nCnt2] = 0;
			m_apNumber[nCnt][nCnt2] = CNumber::Create(D3DXVECTOR3(pos.x + (size.x * nCnt2) * 1.6f, pos.y + (size.y * nCnt) * 2.2f, 0.0f), D3DXVECTOR3(size.x, size.y, 0.0f));
		}
	}

	//�v���C�f�[�^�̎擾
	CData *pData = NULL;
	pData = CManager::GetData();

	//���[�h����
	FILE *pFile;
	pFile = fopen("data/ranking.txt", "r");

	if (pFile != NULL)
	{
		for (int nCntRanking = 0; nCntRanking < 5; nCntRanking++)
		{
			fscanf(pFile, "%d", &m_nRank[nCntRanking]);
		}
	}
	else
	{
		printf("�t�@�C�����J���܂���ł���\n");
	}
	fclose(pFile);

	if (pData->GetScore() < m_nRank[5 - 1])	m_nRank[5 - 1] = pData->GetScore();

	//�\�[�g
	for (int nRank1 = 0; nRank1 < 5; nRank1++)
	{
		for (int nRank2 = 1; nRank2 < 5; nRank2++)
		{
			if (m_nRank[nRank1] > m_nRank[nRank2])
			{
				int nScore = m_nRank[nRank1];
				m_nRank[nRank1] = m_nRank[nRank2];
				m_nRank[nRank2] = nScore;
			}
		}
	}

	for (int nRank1 = 5 - 1; nRank1 > 0; nRank1--)
	{
		for (int nRank2 = 5 - 1; nRank2 > 0; nRank2--)
		{
			if (m_nRank[nRank1] > m_nRank[nRank2])
			{
				int nScore = m_nRank[nRank1];
				m_nRank[nRank1] = m_nRank[nRank2];
				m_nRank[nRank2] = nScore;
			}
		}
	}

	//�X�R�A�̐���
	for (int nCntRanking = 0; nCntRanking < 5; nCntRanking++)
	{
		int nRank1 = 10000;
		int nRank2 = 1000;

		if (m_nRank[nCntRanking] > MAX_RANK)
		{
			m_nRank[nCntRanking] = MAX_RANK;
		}

		for (int nCnt = 0; nCnt < RANK_DIGITS; nCnt++)
		{
			m_apNumber[nCntRanking][nCnt]->SetNumber(m_nRank[nCntRanking] % nRank1 / nRank2);

			nRank1 *= 0.1f;
			nRank2 *= 0.1f;
		}
	}

	//�Z�[�u����
	pFile = fopen("data/ranking.txt", "w");
	if (pFile != NULL)
	{
		for (int nCntRanking = 0; nCntRanking < RANK_DIGITS; nCntRanking++)
		{
			fprintf(pFile, "%d\n", m_nRank[nCntRanking]);
		}
	}
	else
	{
		printf("�t�@�C�����J���܂���ł���\n");
	}
	fclose(pFile);
}