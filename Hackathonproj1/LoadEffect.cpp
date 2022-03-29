//=============================================================================
// ロードさせる処理 [Load.cpp]
// Author : 佐藤秀亮
//=============================================================================
//*****************************************************************************
// インクルードファイル
//***************************************************************************** 
#include "LoadEffect.h"
#include "SetEffect.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CLoadEffect::CLoadEffect()
{

}

//=============================================================================
// デストラクタ
//=============================================================================
CLoadEffect::~CLoadEffect()
{

}

//=============================================================================
// エフェクト情報の読み込み
//=============================================================================
void CLoadEffect::EffectStateLoad(const char *aFileName)
{
	FILE *pFile;
	pFile = fopen(aFileName, "r");
	char aFile[256];

	bool bEffectState2D = false;
	int nPattern = 0;
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Addmove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	int Diffusion = 1;
	int Destroyvec = 0;
	float fSize = 0;
	float fAddSize = 0;
	D3DCOLORVALUE col;
	D3DCOLORVALUE ChangeColor;
	int nLife = 0;
	int Density = 1;
	int bRandColR = false;
	int bRandColG = false;
	int bRandColB = false;
	int bMoveRandX = false;
	int bMoveRandY = false;
	int bMousePos = false;

	if (pFile != NULL)
	{
		while (true)
		{
			fscanf(pFile, "%s", &aFile[0]); //fscanfを繰り返してファイルを読み取っていく

			if (bEffectState2D == true)
			{
				if (strcmp(&aFile[0], "PATTERN") == 0)	//動きのパターン
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &nPattern);
				}
				if (strcmp(&aFile[0], "POS") == 0)	//出現位置
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%f %f %f", &pos.x, &pos.y, &pos.z);
				}
				if (strcmp(&aFile[0], "MOVE") == 0)	//移動量
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%f %f %f", &move.x, &move.y, &move.z);
				}
				if (strcmp(&aFile[0], "ADDMOVE") == 0)	//動き加算
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%f %f %f", &Addmove.x, &Addmove.y, &Addmove.z);
				}
				if (strcmp(&aFile[0], "DIFFUSION") == 0)	//拡散率
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &Diffusion);
				}
				if (strcmp(&aFile[0], "DESTROYVEC") == 0)	//消えるベクトル
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &Destroyvec);
				}
				if (strcmp(&aFile[0], "SIZE") == 0)	//大きさ
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%f", &fSize);
				}
				if (strcmp(&aFile[0], "ADDSIZE") == 0)	//大きさ加算
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%f", &fAddSize);
				}
				if (strcmp(&aFile[0], "COLOR") == 0)	//カラー
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%f %f %f %f", &col.r, &col.g, &col.b, &col.a);
				}
				if (strcmp(&aFile[0], "CHANGECOLOR") == 0)	//カラー変動
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%f %f %f %f", &ChangeColor.r, &ChangeColor.g, &ChangeColor.b, &ChangeColor.a);
				}
				if (strcmp(&aFile[0], "LIFE") == 0)	//寿命
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &nLife);
				}
				if (strcmp(&aFile[0], "DENSITY") == 0)	//密度
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &Density);
				}
				if (strcmp(&aFile[0], "COLORRANDR") == 0)	//カラーランダム赤
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &bRandColR);
				}
				if (strcmp(&aFile[0], "COLORRANDG") == 0)	//カラーランダム緑
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &bRandColG);
				}
				if (strcmp(&aFile[0], "COLORRANDB") == 0)	//カラーランダム青
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &bRandColB);
				}
				if (strcmp(&aFile[0], "MOVERANDX") == 0)	//移動ランダムX
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &bMoveRandX);
				}
				if (strcmp(&aFile[0], "MOVERANDY") == 0)	//移動ランダムY
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &bMoveRandY);
				}
				if (strcmp(&aFile[0], "MOUSEPOS") == 0)		//マウス追従(プレイヤー追従だったり)
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &bMousePos);
				}
			}

			//エフェクト情報セット
			if (strcmp(&aFile[0], "EFFECTSTATE2D") == 0)
			{
				bEffectState2D = true;
			}
			if (strcmp(&aFile[0], "END_EFFECTSTATE2D") == 0)
			{
				bEffectState2D = false;
				CSetEffect::SetEffectState2D(nPattern,pos, move, Addmove, Diffusion, Destroyvec, fSize, fAddSize, col, ChangeColor, nLife, Density,
					bRandColR, bRandColG, bRandColB, bMoveRandX, bMoveRandY, bMousePos);
			}

			//終わり
			if (strcmp(&aFile[0], "END_SCRIPT") == 0)
			{
				break;
			}
		}
	}
	fclose(pFile);
	CSetEffect::ResetPattern();
}
