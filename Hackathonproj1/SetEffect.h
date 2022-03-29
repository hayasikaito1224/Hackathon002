//*****************************************************************************
// エフェクト設置処理 [SetEffect.h]
// Author : 佐藤秀亮
//*****************************************************************************
#ifndef _SETEFFECT_H_
#define _SETEFFECT_H_
#include "main.h"

//*****************************************************************************
// マクロ
//*****************************************************************************
#define MAX_EFFECTPATTERN_2D (8)


class CSetEffect
{
public:
	//2D用のエフェクトステータス集
	typedef struct
	{
		int m_nPattern;			//動きのパターン
		D3DXVECTOR3 m_pos;		//位置
		float m_fRotate;		//回転
		D3DXVECTOR3 m_Endpos;	//向かうべき位置
		D3DXVECTOR3 m_move;		//移動量
		D3DXVECTOR3 m_Addmove;	//移動量加算
		int m_nDiffusion;		//拡散率
		int m_nDestroyvec;		//消えるベクトル
		float m_fSize;			//サイズ
		float m_fAddSize;		//サイズ加算
		D3DCOLORVALUE m_Col;			//カラー
		D3DCOLORVALUE m_Changecolor;	//カラー加算
		int m_nLife;				//寿命
		int m_nDensity;			//密度
		bool m_bColorRandR;		//色ランダムR
		bool m_bColorRandG;		//色ランダムG
		bool m_bColorRandB;		//色ランダムB
		bool m_bMoveRandX;			//移動量ランダムX
		bool m_bMoveRandY;		//移動量ランダムY
		bool m_bMousePos;
	} EFFECT_STATE2D;

	CSetEffect();
	~CSetEffect();


	//読み込んだエフェクトの情報を格納するやつ
	static void SetEffectState2D(int nPattern,
		D3DXVECTOR3 pos,
		float fRotate,
		D3DXVECTOR3 move,
		D3DXVECTOR3 Addmove,
		int Diffusion,
		int Destroyvec,
		float fSize,
		float m_fAddSize,
		D3DCOLORVALUE col,
		D3DCOLORVALUE Changecolor,
		int nLife,
		int nDensity,
		bool bColorRandR,
		bool bColorRandG,
		bool bColorRandB,
		bool bMoveRandX,
		bool bMoveRandY,
		bool bMousePos);

	static void SetEffect(int nPattern, D3DXVECTOR3 pos, D3DXVECTOR3 Endpos);

	static void ResetPattern() { m_nEffectPattern = 0; }
private:
	static EFFECT_STATE2D m_EffectState2D[MAX_EFFECTPATTERN_2D];
	static int m_nEffectPattern;	//複数のやつ読み込めるようにするやつ

};
#endif // !_SETEFFECT_H_