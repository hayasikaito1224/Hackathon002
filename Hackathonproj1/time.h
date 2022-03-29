//=============================================================================
//
// 残り時間 [time.h]
// Author : 三橋錬
//
//=============================================================================
#ifndef _TIME_H_
#define _TIME_H_

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include "main.h"
#include "number.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define TIME_DIGITS (2)				// 桁数
#define MAX_TIME (99)

//*****************************************************************************
// クラス定義
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
	int								m_nCommaTime;	// 0.1秒

	D3DXVECTOR3						m_pos;
	D3DXVECTOR3						m_size;

	bool							m_bNextMode;
};

#endif