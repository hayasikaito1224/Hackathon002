//=============================================================================
//
// テクスチャ処理 [texture.h]
// Author : 羽鳥太一
//
//=============================================================================
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include "main.h"

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CTexture
{
public:
	CTexture();	// デフォルトコンストラクタ
	~CTexture();// デフォルトデストラクタ
	typedef enum
	{
		None = -1,		// テクスチャ無し
		Test,			// 仮テクスチャ
		Number,			// 番号
		Bag,			// 袋
		GameBg,			//ゲームの背景
		Balance,		//秤
		Fade,			//フェード
		TitleLogo,		// タイトルロゴ
		TitleEnter,		// タイトル文字
		TitleBG,		// タイトル背景
		Effect,			//エフェクト（粒）
		Star,			//エフェクト（星）
		Max,			// テクスチャの最大数
	} Type;

	void Init(void);	// テクスチャの生成
	LPDIRECT3DTEXTURE9 GetTexture(Type Type) { return m_pTexture[Type]; }	// テクスチャの割り当て(テクスチャの種類) { return 選んだテクスチャを返す }
	void Uniinit(void);	// 終了

private:
	LPDIRECT3DTEXTURE9	m_pTexture[Max];	//テクスチャ
};

#endif