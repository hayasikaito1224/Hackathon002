//*****************************************************************************
// (�ڕW�Ɍ������Ĕ��ł�)�G�t�F�N�g���� [MouseTracking.h]
// Author : �����G��
//*****************************************************************************
#ifndef _MOUSETRACKING_H_
#define _MOUSETRACKING_H_

#include "effect.h"

class CMouseTracking : public CEffect
{
public:
	CMouseTracking(int nPriority);
	~CMouseTracking();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DCOLORVALUE color, D3DCOLORVALUE Mincolor, D3DXVECTOR2 Size, D3DXVECTOR2 MinSize, int nLife, int nType, D3DXVECTOR3 Endpos, int Diffusion, int UninitVectl);
	void Uninit();
	void Update();
	void Draw();

	static CMouseTracking *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DCOLORVALUE color, D3DCOLORVALUE Mincolor, D3DXVECTOR2 Size, D3DXVECTOR2 MinSize, int nLife, int nType, D3DXVECTOR3 Endpos,int Diffusion, int UninitVectl);
private:
	D3DXVECTOR3 m_move;
	D3DXVECTOR3 m_Vec;
	D3DXVECTOR3 m_Endpos;

	float m_fAngle;
	float m_Vectl;
	int m_UninitVectl;
};

#endif // !_MOUSETRACKING_H_
