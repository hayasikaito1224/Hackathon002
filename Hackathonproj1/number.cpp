//=============================================================================
//
// 数字 [number.cpp]
// Author : 三橋錬
//
//=============================================================================
#include "number.h"
#include "manager.h"
#include "renderer.h"

LPDIRECT3DTEXTURE9	CNumber::m_pTexture = NULL;

//=============================================================================
// コンストラクタ
//=============================================================================
CNumber::CNumber(CScene::OBJTYPE nPriority)
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//=============================================================================
// デストラクタ
//=============================================================================
CNumber::~CNumber()
{

}

//=============================================================================
// ポリゴンの初期化処理
//=============================================================================
HRESULT CNumber::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	m_pos = pos;
	m_size = size;

	// 頂点情報を設定
	LPDIRECT3DDEVICE9 pDevice;						//デバイスのポインタ
	pDevice = CManager::GetRenderer()->GetDevice();	//デバイスを取得

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D *pVtx;					//頂点情報へのポインタ

										//頂点バッファをロックし、頂点データへのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y - m_size.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y - m_size.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y + m_size.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y + m_size.y, 0.0f);

	//rhwの設定(1.0f固定)
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//頂点バッファをアンロック
	m_pVtxBuff->Unlock();

	m_pTexture = CManager::GetTexture()->GetTexture(CTexture::Number);

	return S_OK;
}

//=============================================================================
// ポリゴンの終了処理
//=============================================================================
void CNumber::Uninit(void)
{
	//頂点バッファ破棄
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
}

//=============================================================================
// ポリゴンの更新処理
//=============================================================================
void CNumber::Update(void)
{

}

//=============================================================================
// ポリゴンの描画処理
//=============================================================================
void CNumber::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice;						//デバイスのポインタ
	pDevice = CManager::GetRenderer()->GetDevice();	//デバイスを取得

													// 頂点フォーマットの設定
	pDevice->SetStreamSource(
		0,
		m_pVtxBuff,
		0,
		sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);					//頂点フォーマットの設定
	pDevice->SetTexture(0, m_pTexture);				//テクスチャの設定

													// ポリゴンの描画
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,						//プリミティブの種類
		0,											//開始する頂点のインデックス
		2);											//プリミティブの数
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
	VERTEX_2D *pVtx;										//頂点情報へのポインタ

															//頂点バッファをロックし、頂点データへのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(nNum * 0.1f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(nNum * 0.1f + 0.1f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(nNum * 0.1f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(nNum * 0.1f + 0.1f, 1.0f);

	//頂点バッファをアンロック
	m_pVtxBuff->Unlock();
}

void CNumber::Blink(bool blink)		// 点滅
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

	VERTEX_2D *pVtx;										//頂点情報へのポインタ

															//頂点バッファをロックし、頂点データへのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, nBlink);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, nBlink);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, nBlink);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, nBlink);

	//頂点バッファをアンロック
	m_pVtxBuff->Unlock();
}