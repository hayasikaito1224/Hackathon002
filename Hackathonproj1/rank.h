//=============================================================================
//
// �����L���O [rank.h]
// Author : �O���B
//
//=============================================================================
#ifndef _RANK_H_
#define _RANK_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "main.h"
#include "number.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define RANK_DIGITS (4)				// �X�R�A�̌���
#define MAX_RANK (9999)

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CRank : public CScene
{
public:
	CRank(OBJTYPE nPriority = CScene::OBJTYPE_UI);
	~CRank();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CRank *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	void SetRank(int num, int nRank);

private:
	void Set(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	CNumber							*m_apNumber[5][RANK_DIGITS];
	int								m_nRank[5];

	D3DXVECTOR3						m_pos;
	D3DXVECTOR3						m_size;
};

#endif