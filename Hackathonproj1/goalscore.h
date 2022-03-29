//=============================================================================
//
// �ڕW�̏d�� [goalscore.h]
// Author : �O���B
//
//=============================================================================
#ifndef _GOALSCORE_H_
#define _GOALSCORE_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "main.h"
#include "number.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define GOAL_DIGITS (4)				// �X�R�A�̌���
#define MAX_GOAL (9999)

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CGoalScore : public CScene
{
public:
	CGoalScore(OBJTYPE nPriority = CScene::OBJTYPE_UI);
	~CGoalScore();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CGoalScore *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	void SetScore(int nGoalScore);
	int GetScore() { return m_nGoalScore; }

private:
	void Set(D3DXVECTOR3 pos, D3DXVECTOR3 size);

	CNumber							*m_apNumber[GOAL_DIGITS];
	int								m_nGoalScore;

	D3DXVECTOR3						m_pos;
	D3DXVECTOR3						m_size;
};

#endif