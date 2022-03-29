//*****************************************************************************
// �G�t�F�N�g�ݒu���� [SetEffect.cpp]
// Author : �����G��
//*****************************************************************************
//*****************************************************************************
// �C���N���[�h�t�@�C��
//***************************************************************************** 
#include "SetEffect.h"

#include "MouseTracking.h"
#include "Movement.h"
#include <assert.h>

//*****************************************************************************
// �}�N��
//***************************************************************************** 
#define RAND_MOVE ((float(rand() % 300) + 100) / 100)//�����_���ړ��l
#define RAND_MOVEMIN ((float(rand() % 1)) - (float(rand() % 10)))//�����_���ړ��l
#define RAND_COLOR ((float(rand()% 10) + 1) / 10)		//�����_���J���[


//*****************************************************************************
// �ÓI
//***************************************************************************** 
int CSetEffect::m_nEffectPattern = 0;
CSetEffect::EFFECT_STATE2D CSetEffect::m_EffectState2D[MAX_EFFECTPATTERN_2D] = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CSetEffect::CSetEffect()
{
	m_EffectState2D[MAX_EFFECTPATTERN_2D] = {};
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CSetEffect::~CSetEffect()
{
	m_nEffectPattern = 0;
}

//=============================================================================
// �ϐ��ɂԂ����ފ֐� 2D�p
//=============================================================================
void CSetEffect::SetEffectState2D(int nPattern,
	D3DXVECTOR3 pos,
	D3DXVECTOR3 move,
	D3DXVECTOR3 Addmove,
	int Diffusion,
	int Destroyvec,
	float fSize,
	float fAddSize,
	D3DCOLORVALUE col,
	D3DCOLORVALUE Changecolor,
	int nLife,
	int nDensity,
	bool bColorRandR,
	bool bColorRandG,
	bool bColorRandB,
	bool bMoveRandX,
	bool bMoveRandY,
	bool bMousePos)
{
	m_EffectState2D[m_nEffectPattern].m_nPattern = nPattern;
	m_EffectState2D[m_nEffectPattern].m_pos = pos;
	m_EffectState2D[m_nEffectPattern].m_move = move;
	m_EffectState2D[m_nEffectPattern].m_Addmove = Addmove;
	m_EffectState2D[m_nEffectPattern].m_nDiffusion = Diffusion;
	m_EffectState2D[m_nEffectPattern].m_nDestroyvec = Destroyvec;
	m_EffectState2D[m_nEffectPattern].m_fSize = fSize;
	m_EffectState2D[m_nEffectPattern].m_fAddSize = fAddSize;
	m_EffectState2D[m_nEffectPattern].m_Col = col;
	m_EffectState2D[m_nEffectPattern].m_Changecolor = Changecolor;
	m_EffectState2D[m_nEffectPattern].m_nLife = nLife;
	m_EffectState2D[m_nEffectPattern].m_nDensity = nDensity;
	m_EffectState2D[m_nEffectPattern].m_bColorRandR = bColorRandR;
	m_EffectState2D[m_nEffectPattern].m_bColorRandG = bColorRandG;
	m_EffectState2D[m_nEffectPattern].m_bColorRandB = bColorRandB;
	m_EffectState2D[m_nEffectPattern].m_bMoveRandX = bMoveRandX;
	m_EffectState2D[m_nEffectPattern].m_bMoveRandY = bMoveRandY;
	m_EffectState2D[m_nEffectPattern].m_bMousePos = bMousePos;

	m_nEffectPattern++;
}

//=============================================================================
// �Ă΂ꂽ�����Ăяo�����
//=============================================================================
void CSetEffect::SetEffect(int nPattern, D3DXVECTOR3 pos, D3DXVECTOR3 Endpos)
{
	switch (m_EffectState2D[nPattern].m_nPattern)
	{
	case(1):
		for (int nCnt = 0; nCnt < m_EffectState2D[nPattern].m_nDensity; nCnt++)
		{
			//�e�F�̃����_����
			if (m_EffectState2D[nPattern].m_bColorRandR == true)
			{
				m_EffectState2D[nPattern].m_Col.r = RAND_COLOR;
			}
			if (m_EffectState2D[nPattern].m_bColorRandG == true)
			{
				m_EffectState2D[nPattern].m_Col.g = RAND_COLOR;
			}
			if (m_EffectState2D[nPattern].m_bColorRandB == true)
			{
				m_EffectState2D[nPattern].m_Col.b = RAND_COLOR;
			}

			//�ړ��l�̃����_��
			if (m_EffectState2D[nPattern].m_bMoveRandX == true)
			{
				float f = RAND_MOVE * -1;

				m_EffectState2D[nPattern].m_move.x = f;
			}
			//�ړ��l�̃����_��
			if (m_EffectState2D[nPattern].m_bMoveRandY == true)
			{
				m_EffectState2D[nPattern].m_move.y = RAND_MOVEMIN;
			}

			//�o���ʒu�������̈ʒu��
			if (m_EffectState2D[nPattern].m_bMousePos == true)
			{
				m_EffectState2D[nPattern].m_pos = pos;
			}

			CMovement::Create(m_EffectState2D[nPattern].m_pos,
				m_EffectState2D[nPattern].m_move,
				m_EffectState2D[nPattern].m_Col,
				m_EffectState2D[nPattern].m_Changecolor,
				D3DXVECTOR2(m_EffectState2D[nPattern].m_fSize, m_EffectState2D[nPattern].m_fSize),
				D3DXVECTOR2(m_EffectState2D[nPattern].m_fAddSize, m_EffectState2D[nPattern].m_fAddSize),
				m_EffectState2D[nPattern].m_nLife, 9,
				m_EffectState2D[nPattern].m_Addmove);
		}
		break;
	case(2):
		for (int nCnt = 0; nCnt < m_EffectState2D[nPattern].m_nDensity; nCnt++)
		{
			//�o���ʒu�������̈ʒu��
			if (m_EffectState2D[nPattern].m_bMousePos == true)
			{
				m_EffectState2D[nPattern].m_pos = pos;
			}
			//�e�F�̃����_����4
			if (m_EffectState2D[nPattern].m_bColorRandR == true)
			{
				m_EffectState2D[nPattern].m_Col.r = RAND_COLOR;
			}
			if (m_EffectState2D[nPattern].m_bColorRandG == true)
			{
				m_EffectState2D[nPattern].m_Col.g = RAND_COLOR;
			}
			if (m_EffectState2D[nPattern].m_bColorRandB == true)
			{
				m_EffectState2D[nPattern].m_Col.b = RAND_COLOR;
			}
			//�ړ��l�̃����_��
			if (m_EffectState2D[nPattern].m_bMoveRandX == true)
			{
				m_EffectState2D[nPattern].m_move.x = RAND_MOVEMIN;
			}

			CMouseTracking::Create(pos,
				m_EffectState2D[nPattern].m_move,
				m_EffectState2D[nPattern].m_Col,
				m_EffectState2D[nPattern].m_Changecolor,
				D3DXVECTOR2(m_EffectState2D[nPattern].m_fSize, m_EffectState2D[nPattern].m_fSize),
				D3DXVECTOR2(m_EffectState2D[nPattern].m_fAddSize, m_EffectState2D[nPattern].m_fAddSize),
				m_EffectState2D[nPattern].m_nLife, 9,
				Endpos, m_EffectState2D[nPattern].m_nDiffusion,
				m_EffectState2D[nPattern].m_nDestroyvec);
		}
		break;
	default:
		assert(false);
		break;
	}
}

