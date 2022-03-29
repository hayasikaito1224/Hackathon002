//*****************************************************************************
// �G�t�F�N�g���� [Effect.cpp]
// Author : �����G��
//*****************************************************************************

#include "Effect.h"
#include "manager.h"
#include "Renderer.h"

//*****************************************************************************
//�R���X�g���N�^
//*****************************************************************************
<<<<<<< HEAD
CEffect::CEffect(OBJTYPE nPriority) : CScene2D(nPriority)
=======
<<<<<<< HEAD
CEffect::CEffect(int nPriority) : CScene2D(OBJTYPE_EFFECT)
=======
CEffect::CEffect(OBJTYPE nPriority) : CScene(nPriority)
>>>>>>> 67577fbc9be71ca3b64adcba33a82070c32b98f4
>>>>>>> 6dbe3de064c2bdf49ff160607d3491d8b1c5c6bc
{
	m_Color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
	m_MinColor = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
}

//*****************************************************************************
//�f�X�g���N�^
//*****************************************************************************
CEffect::~CEffect()
{

}

//*****************************************************************************
//������
//*****************************************************************************
HRESULT CEffect::Init(D3DXVECTOR3 pos, D3DCOLORVALUE color, D3DCOLORVALUE Mincolor, D3DXVECTOR2 Size, D3DXVECTOR2 MinSize, int nLife, int nType)
{
	CScene2D::Init();

	m_Color = color;
	m_MinColor = Mincolor;

	m_Size = Size;
	m_MinSize = MinSize;

	m_nLife = nLife;
	m_bUninit = false;

	SetCol(m_Color);
	CScene2D::SetPos(pos, D3DXVECTOR3(Size.x, Size.y, {}));	//�I�������ԍ��̃e�N�X�`����\��

	return S_OK;
}

//*****************************************************************************
//�I��
//*****************************************************************************
void CEffect::Uninit()
{
	CScene2D::Uninit();
}

//*****************************************************************************
//�X�V
//*****************************************************************************
void CEffect::Update()
{
	D3DXVECTOR3 pos = GetPos();

	m_Size += m_MinSize;

	//�T�C�Y�ύX
	CScene2D::SetPos(pos, D3DXVECTOR3(m_Size.x, m_Size.y, {}));	//�I�������ԍ��̃e�N�X�`����\��
	m_nLife--;		//���C�t���Z

	//��ʊO����
	if (pos.y < 0)
	{
		m_bUninit = true;
	}
	else if (pos.y > SCREEN_HEIGHT)
	{
		m_bUninit = true;
	}
	if (pos.x < 0)
	{
		m_bUninit = true;
	}
	else if (pos.x > SCREEN_WIDTH)
	{
		m_bUninit = true;
	}


	//����������0�ɂȂ�����
	if (m_Size.x < 0 || m_Size.y < 0)
	{
		m_bUninit = true;
	}
	//������0�ɂȂ�����
	if (m_nLife < 0)
	{
		m_bUninit = true;
	}

	//�J���[�ύX
	m_Color.r += m_MinColor.r;
	m_Color.g += m_MinColor.g;
	m_Color.b += m_MinColor.b;
	m_Color.a += m_MinColor.a;

	//�J���[��0�ȉ��̎�
	if (m_Color.r < 0)
	{
		m_Color.r = 0;
	}
	if (m_Color.g < 0)
	{
		m_Color.g = 0;
	}
	if (m_Color.b < 0)
	{
		m_Color.b = 0;
	}
	if (m_Color.a < 0)
	{
		m_Color.a = 0;
	}

	//�J���[��255�ȏ�̎�
	if (m_Color.r > 255)
	{
		m_Color.r = 255;
	}
	if (m_Color.g > 255)
	{
		m_Color.g = 255;
	}
	if (m_Color.b > 255)
	{
		m_Color.b = 255;
	}
	if (m_Color.a > 255)
	{
		m_Color.a = 255;
	}
	SetCol(m_Color);

	//�j��
	if (m_bUninit == true)
	{
		Uninit();
	}

}

//*****************************************************************************
// �`��
//*****************************************************************************
void CEffect::Draw()
{
	// ���_����ݒ�
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̎擾

	//Z�e�X�g�֌W
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

	//���Z�����֌W
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	//�A���t�@�e�X�g�֌W
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);

	CScene2D::Draw();

	//Z�e�X�g�֌W
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	//�A���t�@�e�X�g�֌W
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0x00);

	//�ʏ퍇���ɖ߂�(���Z����)
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);


}


