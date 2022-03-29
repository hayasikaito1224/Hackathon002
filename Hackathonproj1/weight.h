//=============================================================================
//
// 砂の重量 [weight.h]
// Author : 三橋錬
//
//=============================================================================
#ifndef _WEIGHT_H_
#define _WEIGHT_H_

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include "main.h"
#include "number.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define WEIGHT_DIGITS (3)				// 桁数
#define MAX_WEIGHT (999)

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CWeight : public CScene
{
public:
	CWeight(OBJTYPE nPriority = CScene::OBJTYPE_UI);
	~CWeight();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CWeight *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	void SetWeight(int nWeight);
	int GetWeight() { return m_nWeight; }

private:
	void Set(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	CNumber							*m_apNumber[WEIGHT_DIGITS];
	int								m_nWeight;

	D3DXVECTOR3						m_pos;
	D3DXVECTOR3						m_size;
};

#endif