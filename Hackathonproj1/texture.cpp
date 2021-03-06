//=============================================================================
//
// テクスチャ処理 [texture.cpp]
// Author : 羽鳥太一作
//
//=============================================================================
//=============================================================================
// インクルード
//=============================================================================
#include "texture.h"
#include "Renderer.h"
#include "manager.h"

//=============================================================================
// デフォルトコンストラクタ
//=============================================================================
CTexture::CTexture()
{

}

//=============================================================================
// デフォルトデストラクタ
//=============================================================================
CTexture::~CTexture()
{

}

//=============================================================================
// テクスチャの生成
//=============================================================================
void CTexture::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice; //デバイスのポインタ
	pDevice = CManager::GetRenderer()->GetDevice();	//デバイスを取得する

	D3DXCreateTextureFromFile(pDevice,
		"",	// 無し
		&m_pTexture[None]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/test_texture.png",//仮テクスチャ
		&m_pTexture[Test]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/number.png",//番号
		&m_pTexture[Number]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Hukuro.png",//袋
		&m_pTexture[Bag]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/BackGround.png",//ゲーム背景
		&m_pTexture[GameBg]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Hakari.png",//秤
		&m_pTexture[Balance]);

	//テクスチャの読み込み 
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/black.png",//フェード
		&m_pTexture[Fade]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/TitleLogo.png",//タイトルロゴ
		&m_pTexture[TitleLogo]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/TitleEnter.png",//タイトル文字
		&m_pTexture[TitleEnter]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/TitleBG.jpg",//タイトル背景
		&m_pTexture[TitleBG]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Effect000.jpg",//エフェクト（粒）
		&m_pTexture[Effect]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/star.png",//エフェクト（星）
		&m_pTexture[Star]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Start000.png",//スタート文字
		&m_pTexture[Start]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Finish000.png",//フィニッシュ文字
		&m_pTexture[Finish]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/rule.png",//ルール
		&m_pTexture[Rule]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Signboard.png",//看板
		&m_pTexture[SignBoard]);

	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/ResultBG.jpg",//リザルトの背景
		&m_pTexture[ResultBg]);

}

//=============================================================================
// 終了
//=============================================================================
void CTexture::Uniinit(void)
{
	for (int nCntTexture = 0; nCntTexture < Max; nCntTexture++)
	{
		//テクスチャの破棄
		if (m_pTexture[nCntTexture] != NULL)
		{
			m_pTexture[nCntTexture]->Release();
			m_pTexture[nCntTexture] = NULL;
		}
	}
}