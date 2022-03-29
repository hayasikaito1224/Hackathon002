//--------------------------------------
//���U���g��ʂ̏���
//--------------------------------------
#include "result.h"
#include "bg.h"
#include "texture.h"
#include "manager.h"
#include "keyboard.h"
#include "fade.h"
#include "Polygon.h"
#include "XInput.h"
#include "sound.h"
#include "score.h"
#include "weight.h"
#include "goalscore.h"
#include "rank.h"
#include "directinput.h"

CBg *CResult::m_pBg = NULL;
CScore *CResult::m_pScore = nullptr;
CWeight *CResult::m_Weight = nullptr;
CGoalScore *CResult::m_GoalScore = nullptr;
//CRank *CResult::m_Rank = nullptr;

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CResult::CResult()
{
	m_bNextMode = false;
	m_Cursol = NULL;
	m_pScore = NULL;
	m_Weight = NULL;
	m_GoalScore = NULL;
	//m_Rank = NULL;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CResult::~CResult()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CResult::Init(void)
{
	m_bNextMode = false;
	//m_pBg = CBg::Create(CTexture::GameClear000, CScene::OBJTYPE_BG, false);	//�w�i
	//pPolygon[1] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 80.0f, 0.0f), D3DXVECTOR3(200, 40.0f, 0.0f), CTexture::Retry);	//���g���C
	//pPolygon[2] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 200.0f, 0.0f), D3DXVECTOR3(200, 40.0f, 0.0f), CTexture::TitleBack001);	//�^�C�g���ɖ߂�
	//m_Cursol = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 200.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), CTexture::Cursol);	//�^�C�g���ɖ߂�
																																							//m_pBg->SetCol(D3DXCOLOR(0.0, 0.0, 1.0, 1.0));
																																						//���p�����̐���

	if (!m_pScore)
	{
		m_pScore = CScore::Create(D3DXVECTOR3(SCREEN_WIDTH / 2 - 100.0f, 125.0f, 0.0f), D3DXVECTOR3(25.0f, 45.0f, 0.0f));
	}
	
	//���p�����̐���
	if (!m_Weight)
	{
		m_Weight = CWeight::Create(D3DXVECTOR3(200.0f, 50.0f, 0.0f), D3DXVECTOR3(25.0f, 45.0f, 0.0f));
	}

	//�ڕW�d�ʗp�����̐���
	if (!m_GoalScore)
	{
		m_GoalScore = CGoalScore::Create(D3DXVECTOR3(200.0f, 150.0f, 0.0f), D3DXVECTOR3(25.0f, 45.0f, 0.0f));
	}

	//�ڕW�d�ʗp�����̐���
	//if (!m_Rank)
	//{
	//	m_Rank = CRank::Create(D3DXVECTOR3(500.0f, 250.0f, 0.0f), D3DXVECTOR3(25.0f, 45.0f, 0.0f));
	//}

	return S_OK;
}

//--------------------------------------------
//�I��
//--------------------------------------------
void CResult::Uninit(void)
{
	if (m_pBg != NULL)
	{
		m_pBg->Uninit();
		m_pBg = NULL;
	}
	for (int nCnt = 0; nCnt < MAX_RESULT; nCnt++)
	{
		if (pPolygon[nCnt] != NULL)
		{
			pPolygon[nCnt]->Uninit();
			pPolygon[nCnt] = NULL;
		}
	}

	if (m_pScore != nullptr)
	{
		m_pScore->Uninit();
		m_pScore = nullptr;
	}

	if (m_Cursol != NULL)
	{
		m_Cursol->Uninit();
		m_Cursol = NULL;
	}

	if (m_Weight != nullptr)
	{
		m_Weight->Uninit();
		m_Weight = nullptr;
	}

	if (m_GoalScore != nullptr)
	{
		m_GoalScore->Uninit();
		m_GoalScore = nullptr;
	}

	//if (m_Rank != nullptr)
	//{
	//	m_Rank->Uninit();
	//	m_Rank = nullptr;
	//}
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CResult::Update(void)
{

	CXInput *pGamePad = CManager::GetXInput();
	CInputKeyBoard *pKeyBoard = CManager::GetInputKeyboard();

	//A�{�^����������
	if (pGamePad->GetButtonTrigger(XINPUT_GAMEPAD_A) == true ||
		pKeyBoard->GetTrigger(DIK_SPACE) == true ||
		pKeyBoard->GetTrigger(DIK_RETURN) == true)
	{
		if (m_bNextMode == false)
		{
			CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_ENTER);
			CManager::GetSound()->ControllVoice(CSound::SOUND_LABEL_SE_ENTER, 0.6f);

			//�^�C�g���֍s��
			CFade::SetFade(CManager::MODE_TITLE);
			////���ȏ�ʂ�Ȃ��悤�ɂ���
			m_bNextMode = true;
		}
	}
}
//--------------------------------------------
//�`��
//--------------------------------------------

void CResult::Draw(void)
{

}

