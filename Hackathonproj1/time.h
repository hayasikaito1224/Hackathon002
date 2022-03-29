//=============================================================================
//
// �c�莞�� [time.h]
// Author : �O���B
//
//=============================================================================
#ifndef _TIME_H_
#define _TIME_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "main.h"
#include "number.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define TIME_DIGITS (2)				// ����
#define MAX_TIME (99)

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CTime : public CScene
{
public:
	CTime(OBJTYPE nPriority = CScene::OBJTYPE_UI);
	~CTime();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CTime *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	void SetTime(int nTime);
	int GetTimet() { return m_nTime; }

private:
	void Set(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	CNumber							*m_apNumber[TIME_DIGITS];
	int								m_nTime;
	int								m_nCommaTime;	// 0.1�b

	D3DXVECTOR3						m_pos;
	D3DXVECTOR3						m_size;

	bool							m_bNextMode;
};

#endif