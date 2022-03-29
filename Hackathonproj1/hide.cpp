//--------------------------------------
//�Q�[����ʂ̏���
//--------------------------------------
#include "hide.h"
#include "Polygon.h"

#define HIDE_SCALE_X (170.0f)
#define HIDE_SCALE_Y (60.0f)
#define HIDE_POS_X (SCREEN_WIDTH / 2.0f-40.0f)

#define HIDE_MOVESTOP (570.0f)
#define HIDE_MOVE_SPEED (4.0f)

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CHide::CHide()
{
	m_Hide = nullptr;
	m_bUp = false;
	m_bDown = false;
	m_bBase = false;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CHide::~CHide()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CHide::Init()
{
	if (m_Hide == nullptr)
	{
		m_Hide = CScene2D::Create({ HIDE_POS_X,SCREEN_HEIGHT + HIDE_SCALE_Y ,0.0f }, { HIDE_SCALE_X ,HIDE_SCALE_Y ,0.0f }, CTexture::Fade,CScene::OBJTYPE_FADE);
	}
	m_fpos_Y = SCREEN_HEIGHT + HIDE_SCALE_Y;
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CHide::Uninit()
{

	if (m_Hide != nullptr)
	{
		m_Hide->Uninit();
		m_Hide = nullptr;
	}

}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CHide::Update()
{
	//�オ�锻�肪�I���Ȃ�摜���グ��
	if (m_bUp==true)
	{
		UpMove();
	}
	//�����锻�肪�I���Ȃ�摜��������
	if (m_bDown==true)
	{
		DownMove();
	}
	if (m_Hide != nullptr)
	{
		m_Hide->SetPos({ HIDE_POS_X,m_fpos_Y,0.0f }, { HIDE_SCALE_X ,HIDE_SCALE_Y ,0.0f });
	}
}

//--------------------------------------------
//�`��
//--------------------------------------------
void CHide::Draw()
{

}
//--------------------------------------------
//�C���X�^���X����
//--------------------------------------------

CHide * CHide::Create()
{
	//�C���X�^���X����
	CHide *pHide = new CHide;
	if (pHide != NULL)
	{
		pHide->Init();
	}
	return pHide;

}
//--------------------------------------------
//�摜���グ�鏈��
//--------------------------------------------
void CHide::UpMove()
{
	m_fpos_Y -= HIDE_MOVE_SPEED;
	if (m_fpos_Y <= HIDE_MOVESTOP)
	{
		m_fpos_Y = HIDE_MOVESTOP;
	}
}
//--------------------------------------------
//�摜�������鏈��
//--------------------------------------------
void CHide::DownMove()
{
	m_fpos_Y += HIDE_MOVE_SPEED;
	if (m_fpos_Y >= SCREEN_HEIGHT + HIDE_SCALE_Y)
	{
		m_fpos_Y = SCREEN_HEIGHT + HIDE_SCALE_Y;
		m_bBase = true;
	}

}

