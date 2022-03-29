//--------------------------------------
//データの管理クラス
//林海斗
//--------------------------------------
#ifndef _DATA_H_
#define _DATA_H_
#include "main.h"
class CData
{
public:
	CData();
	~CData();
	float GetScore() {return m_fScore;}
	float GetTargetScore() { return m_fTargetScore; }
	bool GetNowGame() { return m_bNowGame; }

	void SetScore(float fScore) { m_fScore = fScore; }
	void SetTargetScore(float fTargetScore) { m_fTargetScore = fTargetScore; }
	void ReverseNowGame() { m_bNowGame = !m_bNowGame; }

private:
	float m_fScore;//スコア
	float m_fTargetScore;//目標のスコア
	bool m_bNowGame;//原罪ゲーム中か
};


#endif // !_DATA_H_
