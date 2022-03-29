//=============================================================================
//
// ���� [number.h]
// Author : �O���B
//
//=============================================================================
#ifndef _NUMBER_H_
#define _NUMBER_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "main.h"
#include "scene2D.h"

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CNumber
{
public:
	CNumber(CScene::OBJTYPE nPriority = CScene::OBJTYPE_UI);
	~CNumber();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CNumber *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	void SetNumber(int nNum);
	void Blink(bool blink);

private:
	static LPDIRECT3DTEXTURE9		m_pTexture;				// �e�N�X�`���ւ̃|�C���^
	LPDIRECT3DVERTEXBUFFER9			m_pVtxBuff;				// ���_�o�b�t�@�ւ̃|�C���^

	D3DXVECTOR3						m_pos;					// �|���S���̈ʒu
	D3DXVECTOR3						m_size;					// �|���S���̈ʒu
};

#endif