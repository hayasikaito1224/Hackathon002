//----------------------------------
//ポリゴンの処理
//-----------------------------------
#include "scene2D.h"
#include "input.h"
#include "Renderer.h"
#include "manager.h"
#include "texture.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CScene2D::CScene2D(OBJTYPE nPriority) :CScene(nPriority)
{
	m_col = { 1.0,1.0,1.0,1.0 };
	m_fAngle = 0.0f;
	m_pTexture = nullptr;
	m_pVtxBuff = nullptr;
}

//=============================================================================
// デストラクタ
//=============================================================================
CScene2D::~CScene2D()
{

}
//---------------------------------------------------------------
//インスタンス生成処理
//---------------------------------------------------------------
CScene2D *CScene2D::Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale, CTexture::Type texture, CScene::OBJTYPE type)
{

	//インスタンス生成
	CScene2D *pScene2D = new CScene2D(type);
	if (pScene2D != NULL)
	{
		pScene2D->m_pos = pos;
		pScene2D->m_scale = scale;
		pScene2D->Init();
		pScene2D->BindTexture(texture);
	}
	return pScene2D;
}

void CScene2D::BindTexture(CTexture::Type type)
{
	m_pTexture = CManager::GetTexture()->GetTexture(type);
}
//=============================================================================
// ポリゴンの初期化処理
//=============================================================================
HRESULT CScene2D::Init(CTexture::Type type)
{

	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//デバイスのポインタ

																	 // 頂点情報を設定
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	m_bUse = true;

	//テクスチャ画像の設定
	m_pTexture = CManager::GetTexture()->GetTexture(type);

	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//バッファの生成
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_scale.x, m_pos.y - m_scale.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_scale.x, m_pos.y - m_scale.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_scale.x, m_pos.y + m_scale.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_scale.x, m_pos.y + m_scale.y, 0.0f);

	pVtx[0].tex = D3DXVECTOR2(0.0, 0.0);
	pVtx[1].tex = D3DXVECTOR2(1.0, 0.0);
	pVtx[2].tex = D3DXVECTOR2(0.0, 1.0);
	pVtx[3].tex = D3DXVECTOR2(1.0, 1.0);

	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	m_pVtxBuff->Unlock();

	return S_OK;
}
HRESULT CScene2D::Init(void)
{

	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//デバイスのポインタ

																	 // 頂点情報を設定
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//バッファの生成
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_scale.x, m_pos.y - m_scale.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_scale.x, m_pos.y - m_scale.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_scale.x, m_pos.y + m_scale.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_scale.x, m_pos.y + m_scale.y, 0.0f);

	pVtx[0].tex = D3DXVECTOR2(0.0, 0.0);
	pVtx[1].tex = D3DXVECTOR2(1.0, 0.0);
	pVtx[2].tex = D3DXVECTOR2(0.0, 1.0);
	pVtx[3].tex = D3DXVECTOR2(1.0, 1.0);

	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	pVtx[0].col = m_col;
	pVtx[1].col = m_col;
	pVtx[2].col = m_col;
	pVtx[3].col = m_col;

	m_pVtxBuff->Unlock();

	return S_OK;
}

//=============================================================================
// ポリゴンの終了処理
//=============================================================================
void CScene2D::Uninit(void)
{
	//頂点バッファの破棄
  	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
	Release();
}

//=============================================================================
// ポリゴンの更新処理
//=============================================================================
void CScene2D::Update(void)
{
	int n = 0;
}

//=============================================================================
// ポリゴンの描画処理
//=============================================================================
void CScene2D::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//デバイスのポインタ

																	 // 頂点フォーマットの設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	pDevice->SetFVF(FVF_VERTEX_2D);//頂点フォーマットの設定
	pDevice->SetTexture(0, m_pTexture);

	// ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,
		0,						//描画を開始する最初の頂点インデックス
		2);						//ポリゴンの数

}
//-------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------
//頂点座標の設定
//------------------------------------------------------------
void CScene2D::SetPos(D3DXVECTOR3 vtx0, D3DXVECTOR3 vtx1, D3DXVECTOR3 vtx2, D3DXVECTOR3 vtx3)
{
	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//バッファの生成
	pVtx[0].pos = vtx0;
	pVtx[1].pos = vtx1;
	pVtx[2].pos = vtx2;
	pVtx[3].pos = vtx3;

	m_pVtxBuff->Unlock();

}
//------------------------------------------------------------
//頂点座標の設定
//------------------------------------------------------------

void CScene2D::SetPos(D3DXVECTOR3 pos, D3DXVECTOR3 scale)
{

	CScene::SetPos(pos);
	CScene::SetScale(scale);

	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//バッファの生成
	pVtx[0].pos = D3DXVECTOR3(pos.x - scale.x, pos.y - scale.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + scale.x, pos.y - scale.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - scale.x, pos.y + scale.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + scale.x, pos.y + scale.y, 0.0f);

	m_pVtxBuff->Unlock();

}


//------------------------------------------------------------
//テクスチャの設定
//------------------------------------------------------------
void CScene2D::SetTex(int nAnim, int nPartU)
{
	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].tex = D3DXVECTOR2(0.0f + (1.0f / nPartU)*nAnim, 0.0);
	pVtx[1].tex = D3DXVECTOR2((1.0f / nPartU)*(nAnim + 1), 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f + (1.0f / nPartU)*nAnim, 1.0f);
	pVtx[3].tex = D3DXVECTOR2((1.0f / nPartU)*(nAnim + 1), 1.0f);

	m_pVtxBuff->Unlock();

}
//------------------------------------------------------------
//テクスチャの設定
//------------------------------------------------------------
void CScene2D::SetTex(int nType, int nPattern, float fSize)
{
	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].tex = D3DXVECTOR2(nPattern * fSize, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(nPattern * fSize + fSize, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(nPattern * fSize, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(nPattern * fSize + fSize, 1.0f);

	m_pVtxBuff->Unlock();

}
void CScene2D::SetTex(float fSpeedX, float fSpeedY)
{
	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].tex = D3DXVECTOR2(0.0f + fSpeedX, 0.0f + fSpeedY);
	pVtx[1].tex = D3DXVECTOR2(1.0f + fSpeedX, 0.0f + fSpeedY);
	pVtx[2].tex = D3DXVECTOR2(0.0f + fSpeedX, 1.0f + fSpeedY);
	pVtx[3].tex = D3DXVECTOR2(1.0f + fSpeedX, 1.0f + fSpeedY);

	m_pVtxBuff->Unlock();
}

void CScene2D::SetCol(D3DXCOLOR col)
{
	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[1].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[2].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[3].col = D3DXCOLOR(col.r, col.g, col.b, col.a);

	m_pVtxBuff->Unlock();

}
//------------------------------------------------------------
//ポリゴンの回転処理
//------------------------------------------------------------
void CScene2D::Rotate()
{
	D3DXVECTOR3 posOrigin[4];
	D3DXVECTOR3 Rotatepos[4];

	//スケールサイズ込みの４頂点
	posOrigin[0].x = -m_scale.x;
	posOrigin[1].x = m_scale.x;
	posOrigin[2].x = -m_scale.x;
	posOrigin[3].x = m_scale.x;

	posOrigin[0].y = -m_scale.y;
	posOrigin[1].y = -m_scale.y;
	posOrigin[2].y = m_scale.y;
	posOrigin[3].y = m_scale.y;

	//回転の計算
	Rotatepos[0].x = (posOrigin[0].x * cosf(m_fAngle)) - (posOrigin[0].y * sinf(m_fAngle));
	Rotatepos[1].x = (posOrigin[1].x * cosf(m_fAngle)) - (posOrigin[1].y * sinf(m_fAngle));
	Rotatepos[2].x = (posOrigin[2].x * cosf(m_fAngle)) - (posOrigin[2].y * sinf(m_fAngle));
	Rotatepos[3].x = (posOrigin[3].x * cosf(m_fAngle)) - (posOrigin[3].y * sinf(m_fAngle));

	Rotatepos[0].y = (posOrigin[0].x * sinf(m_fAngle)) + (posOrigin[0].y * cosf(m_fAngle));
	Rotatepos[1].y = (posOrigin[1].x * sinf(m_fAngle)) + (posOrigin[1].y * cosf(m_fAngle));
	Rotatepos[2].y = (posOrigin[2].x * sinf(m_fAngle)) + (posOrigin[2].y * cosf(m_fAngle));
	Rotatepos[3].y = (posOrigin[3].x * sinf(m_fAngle)) + (posOrigin[3].y * cosf(m_fAngle));

	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//バッファの生成
	pVtx[0].pos = D3DXVECTOR3(m_pos.x + Rotatepos[0].x, m_pos.y + Rotatepos[0].y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + Rotatepos[1].x, m_pos.y + Rotatepos[1].y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x + Rotatepos[2].x, m_pos.y + Rotatepos[2].y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + Rotatepos[3].x, m_pos.y + Rotatepos[3].y, 0.0f);

	m_pVtxBuff->Unlock();

}
//------------------------------------------------------------
//ポリゴンの回転処理
//------------------------------------------------------------
void CScene2D::Rotate(D3DXVECTOR3 pos, D3DXVECTOR3 scale)
{
	D3DXVECTOR3 posOrigin[4];
	D3DXVECTOR3 Rotatepos[4];

	//スケールサイズ込みの４頂点
	posOrigin[0].x = -scale.x;
	posOrigin[1].x = scale.x;
	posOrigin[2].x = -scale.x;
	posOrigin[3].x = scale.x;

	posOrigin[0].y = -scale.y;
	posOrigin[1].y = -scale.y;
	posOrigin[2].y = scale.y;
	posOrigin[3].y = scale.y;

	//回転の計算
	Rotatepos[0].x = (posOrigin[0].x * cosf(m_fAngle)) - (posOrigin[0].y * sinf(m_fAngle));
	Rotatepos[1].x = (posOrigin[1].x * cosf(m_fAngle)) - (posOrigin[1].y * sinf(m_fAngle));
	Rotatepos[2].x = (posOrigin[2].x * cosf(m_fAngle)) - (posOrigin[2].y * sinf(m_fAngle));
	Rotatepos[3].x = (posOrigin[3].x * cosf(m_fAngle)) - (posOrigin[3].y * sinf(m_fAngle));

	Rotatepos[0].y = (posOrigin[0].x * sinf(m_fAngle)) + (posOrigin[0].y * cosf(m_fAngle));
	Rotatepos[1].y = (posOrigin[1].x * sinf(m_fAngle)) + (posOrigin[1].y * cosf(m_fAngle));
	Rotatepos[2].y = (posOrigin[2].x * sinf(m_fAngle)) + (posOrigin[2].y * cosf(m_fAngle));
	Rotatepos[3].y = (posOrigin[3].x * sinf(m_fAngle)) + (posOrigin[3].y * cosf(m_fAngle));
	VERTEX_2D *pVtx;

 	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//バッファの生成
	pVtx[0].pos = D3DXVECTOR3(pos.x + Rotatepos[0].x, pos.y + Rotatepos[0].y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + Rotatepos[1].x, pos.y + Rotatepos[1].y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x + Rotatepos[2].x, pos.y + Rotatepos[2].y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + Rotatepos[3].x, pos.y + Rotatepos[3].y, 0.0f);

	m_pVtxBuff->Unlock();

}
