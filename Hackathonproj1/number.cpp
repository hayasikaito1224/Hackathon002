//=============================================================================
//
// ���� [number.cpp]
// Author : �O���B
//
//=============================================================================
#include "number.h"
#include "manager.h"
#include "renderer.h"

LPDIRECT3DTEXTURE9	CNumber::m_pTexture = NULL;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CNumber::CNumber(CScene::OBJTYPE nPriority)
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CNumber::~CNumber()
{

}

//=============================================================================
// �|���S���̏���������
//=============================================================================
HRESULT CNumber::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	m_pos = pos;
	m_size = size;

	// ���_����ݒ�
	LPDIRECT3DDEVICE9 pDevice;						//�f�o�C�X�̃|�C���^
	pDevice = CManager::GetRenderer()->GetDevice();	//�f�o�C�X���擾

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D *pVtx;					//���_���ւ̃|�C���^

										//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y - m_size.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y - m_size.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y + m_size.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y + m_size.y, 0.0f);

	//rhw�̐ݒ�(1.0f�Œ�)
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N
	m_pVtxBuff->Unlock();

	m_pTexture = CManager::GetTexture()->GetTexture(CTexture::Number);

	return S_OK;
}

//=============================================================================
// �|���S���̏I������
//=============================================================================
void CNumber::Uninit(void)
{
	//���_�o�b�t�@�j��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
}

//=============================================================================
// �|���S���̍X�V����
//=============================================================================
void CNumber::Update(void)
{

}

//=============================================================================
// �|���S���̕`�揈��
//=============================================================================
void CNumber::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice;						//�f�o�C�X�̃|�C���^
	pDevice = CManager::GetRenderer()->GetDevice();	//�f�o�C�X���擾

													// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetStreamSource(
		0,
		m_pVtxBuff,
		0,
		sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);					//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetTexture(0, m_pTexture);				//�e�N�X�`���̐ݒ�

													// �|���S���̕`��
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,						//�v���~�e�B�u�̎��
		0,											//�J�n���钸�_�̃C���f�b�N�X
		2);											//�v���~�e�B�u�̐�
}

CNumber *CNumber::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CNumber* pNumber = new CNumber;

	if (pNumber != NULL)
	{
		pNumber->Init(pos, size);
	}
	return pNumber;
}

void CNumber::SetNumber(int nNum)
{
	VERTEX_2D *pVtx;										//���_���ւ̃|�C���^

															//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(nNum * 0.1f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(nNum * 0.1f + 0.1f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(nNum * 0.1f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(nNum * 0.1f + 0.1f, 1.0f);

	//���_�o�b�t�@���A�����b�N
	m_pVtxBuff->Unlock();
}

void CNumber::Blink(bool blink)		// �_��
{
	int nBlink;

	switch (blink)
	{
	case true:
		nBlink = 0;
		break;

	case false:
		nBlink = 255;
	}

	VERTEX_2D *pVtx;										//���_���ւ̃|�C���^

															//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, nBlink);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, nBlink);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, nBlink);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, nBlink);

	//���_�o�b�t�@���A�����b�N
	m_pVtxBuff->Unlock();
}