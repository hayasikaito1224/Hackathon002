//--------------------------------------
//���̕��ʂ��B���N���X
//--------------------------------------
#ifndef _HIDE_H
#define _HIDE_H
#include "main.h"
#include "scene.h"

//�O���錾
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
	static CHide *Create();//�C���X�^���X��������
	void IsUp(bool bUp) { m_bUp = bUp; }
	void IsDown(bool bDown) { m_bDown = bDown; }
	bool GetPosBase() { return m_bBase; }
private:
	void UpMove();
	void DownMove();
	CScene2D *m_Hide;//�d�ʂ��B���|���S��
	float m_fpos_Y;//Y���̈ʒu
	bool m_bBase;//���̈ʒu�ɖ߂�����
	bool m_bUp;//�オ�邩�̔���
	bool m_bDown;//�����邩�̔���
};


#endif //_HIDE_H