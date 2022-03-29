//*****************************************************************************
// (âÒì])ÉGÉtÉFÉNÉgèàóù [Rotate.h]
// Author : ç≤ì°èGó∫
//*****************************************************************************
#ifndef _ROTATE_H_
#define _ROTATE_H_

#include "Effect.h"

class CRotate : public CEffect
{
public:
	CRotate(OBJTYPE nPriority);
	~CRotate();

	HRESULT Init(D3DXVECTOR3 pos,
		D3DXVECTOR3 move,
		D3DCOLORVALUE color,
		D3DCOLORVALUE Mincolor,
		D3DXVECTOR2 Size,
		D3DXVECTOR2 MinSize,
		int nLife,
		int nType,
		float AddRotate);

	void Uninit();
	void Update();
	void Draw();

	static CRotate*Create(D3DXVECTOR3 pos,
		D3DXVECTOR3 move,
		D3DCOLORVALUE color,
		D3DCOLORVALUE Mincolor,
		D3DXVECTOR2 Size,
		D3DXVECTOR2 MinSize,
		int nLife,
		int nType,
		float AddRotate);
private:
	D3DXVECTOR3 m_move;
	float m_Angle;			//äpìx
	float m_Vectl;	//	íºê¸ãóó£

	float m_AddAngle;	//âÒì]â¡éZ
};

#endif // !_MOVEMENT_H_
