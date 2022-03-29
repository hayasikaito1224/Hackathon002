//*****************************************************************************
// (��])�G�t�F�N�g���� [Rotate.cpp]
// Author : �����G��
//*****************************************************************************
#include "Rotate.h"
#include "manager.h"

//*****************************************************************************
//�R���X�g���N�^
//*****************************************************************************
CRotate::CRotate(OBJTYPE nPriority) : CEffect(nPriority)
{
	m_Angle = {};
	m_AddAngle = {};
	m_move = {};
	m_Vectl = {};
}

//*****************************************************************************
//�f�X�g���N�^
//*****************************************************************************
CRotate::~CRotate()
{

}

//*****************************************************************************
//	������
//*****************************************************************************
HRESULT CRotate::Init(D3DXVECTOR3 pos,
	D3DXVECTOR3 move,
	D3DCOLORVALUE color,
	D3DCOLORVALUE Mincolor,
	D3DXVECTOR2 Size,
	D3DXVECTOR2 MinSize,
	int nLife, int nType,
	float AddRotate)
{
	CEffect::Init(pos, color, Mincolor, Size, MinSize, nLife, nType);
	m_Size = Size;
	m_MinSize = MinSize;
	m_Angle = 0;
	m_Vectl = sqrtf(m_Size.x * m_Size.x + m_Size.y * m_Size.y);
	m_move = move;
	m_AddAngle = AddRotate;

	CScene2D::BindTexture(CTexture::Star);		//�e�N�X�`���\��t��

	return S_OK;
}

//*****************************************************************************
//�I��
//*****************************************************************************
void CRotate::Uninit()
{
	CEffect::Uninit();
}

//*****************************************************************************
//�X�V
//*****************************************************************************
void CRotate::Update()
{
	D3DXVECTOR3 pos = GetPos();
	m_Vectl = sqrtf(m_Size.x * m_Size.x + m_Size.y * m_Size.y);
	pos += D3DXVECTOR3(m_move.x, m_move.y, 0.0f);
	m_Angle += m_AddAngle;

	SetAngle(D3DXToRadian(m_Angle));
	CScene2D::Rotate(pos, D3DXVECTOR3(m_Vectl, m_Vectl, {}));

	CScene::SetPos(pos);

	//CEffect::Update();
}

//*****************************************************************************
//�`��
//*****************************************************************************
void CRotate::Draw()
{
	CEffect::Draw();
}

//*****************************************************************************
//�쐬
//*****************************************************************************
CRotate *CRotate::Create(D3DXVECTOR3 pos,
	D3DXVECTOR3 move,
	D3DCOLORVALUE color,
	D3DCOLORVALUE Mincolor,
	D3DXVECTOR2 Size,
	D3DXVECTOR2 MinSize,
	int nLife,
	int nType,
	float AddRotate)
{
	CRotate *pRotate = NULL;
	pRotate = new CRotate(CScene::OBJTYPE_EFFECT);		//�������m��
																//NULL�`�F�b�N
	if (pRotate != NULL)
	{
		pRotate->Init(pos, move, color, Mincolor, Size, MinSize, nLife, nType, AddRotate);
	}

	return pRotate;
}
