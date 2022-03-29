//--------------------------------------
//�f�[�^�̊Ǘ��N���X
//�ъC�l
//--------------------------------------
#ifndef _DATA_H_
#define _DATA_H_
#include "main.h"
class CData
{
public:
	CData();
	~CData();

	void ResetData();

	float GetScore() {return m_fScore;}
	float GetTargetScore() { return m_fTargetScore; }
	bool GetNowGame() { return m_bNowGame; }

	void SetScore(float fScore) { m_fScore = fScore; }
	void SetTargetScore(float fTargetScore) { m_fTargetScore = fTargetScore; }
	void ReverseNowGame() { m_bNowGame = !m_bNowGame; }

	float GetSandRemaining() { return m_fSandRemaining; }
	void SetSandRemaining(float sand) { m_fSandRemaining = sand; }

private:
	float m_fSandRemaining;//���̎c��
	float m_fScore;//�X�R�A
	float m_fTargetScore;//�ڕW�̃X�R�A
	bool m_bNowGame;//���߃Q�[������
};


#endif // !_DATA_H_
