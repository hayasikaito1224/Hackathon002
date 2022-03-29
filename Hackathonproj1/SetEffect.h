//*****************************************************************************
// �G�t�F�N�g�ݒu���� [SetEffect.h]
// Author : �����G��
//*****************************************************************************
#ifndef _SETEFFECT_H_
#define _SETEFFECT_H_
#include "main.h"

//*****************************************************************************
// �}�N��
//*****************************************************************************
#define MAX_EFFECTPATTERN_2D (8)


class CSetEffect
{
public:
	//2D�p�̃G�t�F�N�g�X�e�[�^�X�W
	typedef struct
	{
		int m_nPattern;			//�����̃p�^�[��
		D3DXVECTOR3 m_pos;		//�ʒu
		float m_fRotate;		//��]
		D3DXVECTOR3 m_Endpos;	//�������ׂ��ʒu
		D3DXVECTOR3 m_move;		//�ړ���
		D3DXVECTOR3 m_Addmove;	//�ړ��ʉ��Z
		int m_nDiffusion;		//�g�U��
		int m_nDestroyvec;		//������x�N�g��
		float m_fSize;			//�T�C�Y
		float m_fAddSize;		//�T�C�Y���Z
		D3DCOLORVALUE m_Col;			//�J���[
		D3DCOLORVALUE m_Changecolor;	//�J���[���Z
		int m_nLife;				//����
		int m_nDensity;			//���x
		bool m_bColorRandR;		//�F�����_��R
		bool m_bColorRandG;		//�F�����_��G
		bool m_bColorRandB;		//�F�����_��B
		bool m_bMoveRandX;			//�ړ��ʃ����_��X
		bool m_bMoveRandY;		//�ړ��ʃ����_��Y
		bool m_bMousePos;
	} EFFECT_STATE2D;

	CSetEffect();
	~CSetEffect();


	//�ǂݍ��񂾃G�t�F�N�g�̏����i�[������
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
	static int m_nEffectPattern;	//�����̂�ǂݍ��߂�悤�ɂ�����

};
#endif // !_SETEFFECT_H_