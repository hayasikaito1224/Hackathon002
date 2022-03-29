//--------------------------------------
//秤の分量を隠すクラス
//--------------------------------------
#ifndef _HIDE_H
#define _HIDE_H
#include "main.h"
#include "scene.h"

//前方宣言
class CPolygon;
class CScene2D;
class CHide
{
public:

	CHide();
	~CHide();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CHide *Create();//インスタンス生成処理
	void IsUp(bool bUp) { m_bUp = bUp; }
	void IsDown(bool bDown) { m_bDown = bDown; }
	bool GetPosBase() { return m_bBase; }
private:
	void UpMove();
	void DownMove();
	CScene2D *m_Hide;//重量を隠すポリゴン
	float m_fpos_Y;//Y軸の位置
	bool m_bBase;//元の位置に戻ったか
	bool m_bUp;//上がるかの判定
	bool m_bDown;//下がるかの判定
};


#endif //_HIDE_H