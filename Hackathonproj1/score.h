//=============================================================================
//
// スコア [score.h]
// Author : 三橋錬
//
//=============================================================================
#ifndef _SCORE_H_
#define _SCORE_H_

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include "main.h"
#include "number.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define SCORE_DIGITS (8)				// スコアの桁数
#define MAX_SCORE (99999999)

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CScore : public CScene
{
public:
	CScore(OBJTYPE nPriority = CScene::OBJTYPE_UI);
	~CScore();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CScore *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	void SetScore(int nScore);
	int GetScore() {return m_nScore; }

private:
	void Set(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	CNumber							*m_apNumber[SCORE_DIGITS];
	int								m_nScore;

	D3DXVECTOR3						m_pos;
	D3DXVECTOR3						m_size;
};

#endif