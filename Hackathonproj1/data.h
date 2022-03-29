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
	void SetScore(float fScore) { m_fScore = fScore; }
	void SetTargetScore(float fTargetScore) { m_fTargetScore = fTargetScore; }

private:
	float m_fScore;//スコア
	float m_fTargetScore;//目標のスコア
};


#endif // !_DATA_H_

