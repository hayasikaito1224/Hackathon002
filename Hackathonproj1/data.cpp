//--------------------------------------
//�f�[�^�̊Ǘ��N���X
//�ъC�l
//--------------------------------------
#include "data.h"
//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CData::CData()
{
	m_fScore = 0.0f;
	m_fTargetScore = 0.0f;
	m_bNowGame = false;
	m_fSandRemaining = 300.0f;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CData::~CData()
{

}

void CData::ResetData()
{
	m_fScore = 0.0f;
	m_fTargetScore = 0.0f;
	m_bNowGame = false;
	m_fSandRemaining = 300.0f;
}