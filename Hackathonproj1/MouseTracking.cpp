//*****************************************************************************
// (�}�E�X�Ɍ������Ĕ��ł�)�G�t�F�N�g���� [MouseTracking.cpp]
// Author : �����G��
//*****************************************************************************
#include "MouseTracking.h"

//*****************************************************************************
//�R���X�g���N�^
//*****************************************************************************
CMouseTracking::CMouseTracking(int nPriority) : CEffect(nPriority)
{
	m_move = {};
	m_Vec = {};
}

//*****************************************************************************
//�f�X�g���N�^
//*****************************************************************************
CMouseTracking::~CMouseTracking()
{

}

//*****************************************************************************
//	������
//*****************************************************************************
HRESULT CMouseTracking::Init(D3DXVECTOR3 pos,
	D3DXVECTOR3 move,
	D3DCOLORVALUE color,
	D3DCOLORVALUE Mincolor,
	D3DXVECTOR2 Size,
	D3DXVECTOR2 MinSize,
	int nLife, int nType,
	D3DXVECTOR3 Endpos,
	int Diffusion,
	int UninitVectl)
{
	CEffect::Init(pos, color, Mincolor, Size, MinSize, nLife, nType);
	m_Endpos = pos;
	m_Vec = pos - Endpos;
	m_move = move;

	m_UninitVectl = UninitVectl;

	float randAngle = float(rand() % Diffusion) - float(rand() % Diffusion);
	randAngle /= 100.0f;

	m_fAngle = (float)atan2(m_Vec.x, m_Vec.y);		//�p�x

	m_fAngle += randAngle;


	return S_OK;
}

//*****************************************************************************
//�I��
//*****************************************************************************
void CMouseTracking::Uninit()
{
	CEffect::Uninit();
}

//*****************************************************************************
//�X�V
//*****************************************************************************
void CMouseTracking::Update()
{
	D3DXVECTOR3 pos = GetPos();

	m_Vec = pos - m_Endpos;

	m_Vectl = sqrtf(m_Vec.x * m_Vec.x + m_Vec.y *  m_Vec.y);

	if (m_Vectl >= m_UninitVectl)
	{
		m_bUninit = true;
	}

	pos += D3DXVECTOR3(sinf(m_fAngle) * -m_move.x, cosf(m_fAngle) * -m_move.x, 0.0f);

	//�K��
	CScene2D::SetPos(pos, D3DXVECTOR3(m_Size.x, m_Size.y, {}));

	CEffect::Update();
}

//*****************************************************************************
//�`��
//*****************************************************************************
void CMouseTracking::Draw()
{
	CEffect::Draw();
}

//*****************************************************************************
//�쐬
//*****************************************************************************
CMouseTracking *CMouseTracking::Create(D3DXVECTOR3 pos, 
	D3DXVECTOR3 move, 
	D3DCOLORVALUE color, 
	D3DCOLORVALUE Mincolor, 
	D3DXVECTOR2 Size, 
	D3DXVECTOR2 MinSize, 
	int nLife, int nType, 
	D3DXVECTOR3 Endpos, 
	int Diffusion,
	int UninitVectl)
{
	CMouseTracking *pMouseTracking = NULL;
	pMouseTracking = new CMouseTracking(3);		//�������m��
										//NULL�`�F�b�N
	if (pMouseTracking != NULL)
	{
		pMouseTracking->Init(pos, move, color, Mincolor, Size, MinSize, nLife, nType, Endpos,Diffusion, UninitVectl);
	}

	return pMouseTracking;
}