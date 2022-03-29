//=============================================================================
//
// 数字 [number.h]
// Author : 三橋錬
//
//=============================================================================
#ifndef _NUMBER_H_
#define _NUMBER_H_

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include "main.h"
#include "scene2D.h"

//*****************************************************************************
// クラス定義
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
	static LPDIRECT3DTEXTURE9		m_pTexture;				// テクスチャへのポインタ
	LPDIRECT3DVERTEXBUFFER9			m_pVtxBuff;				// 頂点バッファへのポインタ

	D3DXVECTOR3						m_pos;					// ポリゴンの位置
	D3DXVECTOR3						m_size;					// ポリゴンの位置
};

#endif