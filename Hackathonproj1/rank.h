//=============================================================================
//
// ランキング [rank.h]
// Author : 三橋錬
//
//=============================================================================
#ifndef _RANK_H_
#define _RANK_H_

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include "main.h"
#include "number.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define RANK_DIGITS (4)				// スコアの桁数
#define MAX_RANK (9999)

//*****************************************************************************
// クラス定義
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