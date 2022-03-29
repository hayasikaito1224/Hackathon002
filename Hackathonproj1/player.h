//=============================================-
//�v���C���[�̏���
//=============================================
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "scene2D.h"
//------------------------------------
//�}�N����`
//------------------------------------
#define PLAYER_POS_X (0.0)
#define PLAYER_POS_Y (0.0)
#define PLAYER_POS_Z (0.0)
#define PLAYER_FALL (-100.0)//��������ɓ���܂ł̈ʒu

class CPlayer : public CScene2D
{
public:
	CPlayer(OBJTYPE nPriority = CScene::OBJTYPE_PLAYER);
	~CPlayer();
	//�ÓI�����o�[�֐�
	static CPlayer *Create();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void Incline();//�܂��X���鏈��

private:
	D3DXVECTOR3 m_pos; //�ʒu
	bool m_bGameStop;
};


#endif // !_PLAYER_H_
