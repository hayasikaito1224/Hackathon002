//=============================================-
//�v���C���[�̏���
//=============================================
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "scene2D.h"
//------------------------------------
//�}�N����`
//------------------------------------

class CPlayer : public CScene
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
	void AddState(float& fAngle);//�X���p�x�̕��
	void DefState(float& fAngle);//�X���p�x�̕��

private:
	CScene2D *m_pPlayer;//����
	bool m_bGameStop;
	float m_fMoveAngle;//�X���̊p�x
	float m_fSandRemaining;//���̎c��


};


#endif // !_PLAYER_H_
