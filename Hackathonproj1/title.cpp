//--------------------------------------
//�}�l�[�W���[�̏���
//--------------------------------------
#include "title.h"
#include "bg.h"
#include "texture.h"
#include "manager.h"
#include "keyboard.h"
#include "fade.h"
#include "Polygon.h"
#include "XInput.h"
#include "sound.h"
#include "directinput.h"

//�G�t�F�N�g
#include "SetEffect.h"

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CTitle::CTitle()
{
	memset(&m_Polygon, NULL, sizeof(m_Polygon));
	m_bOpra = false;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CTitle::~CTitle()
{

}

//--------------------------------------------
//������
//--------------------------------------------
HRESULT CTitle::Init(void)
{
	m_bNextMode = false;
	m_nCount = 0;
	m_bAlpha = false;
	m_nAlpha = 255;
	CBg::Create(CTexture::TitleBG, CScene::OBJTYPE_BG, false);	//�w�i
	
	m_Polygon[0] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH/3.0f, SCREEN_HEIGHT / 2 - 100.0f, 0.0f), D3DXVECTOR3(340.0f, 200.0f, 0.0f), CTexture::TitleLogo);	//�^�C�g�����S
	
	m_Polygon[1] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH/3.0f, SCREEN_HEIGHT / 2 + 200.0f, 0.0f), D3DXVECTOR3(280.0f, 50.0f, 0.0f), CTexture::TitleEnter);	//�G���^�[����

	m_Polygon[2] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 5.0f * 4, SCREEN_HEIGHT / 2.0f, 0.0f), D3DXVECTOR3(220.0f, 280.0f, 0.0f), CTexture::Rule);	//���[��

	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CTitle::Uninit(void)
{
	for (int nCntPolygon = 0; nCntPolygon < MAX_TITLE_POLYGON; nCntPolygon++)
	{
		if (m_Polygon[nCntPolygon] != NULL)
		{
			m_Polygon[nCntPolygon]->Uninit();
			m_Polygon[nCntPolygon] = NULL;
		}
	}

	CManager::GetSound()->StopSound(CSound::SOUND_LABEL_BGM_TITLE);
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CTitle::Update(void)
{
	CXInput *pGamePad = CManager::GetXInput();
	CDirectInput *pDGamePad = CManager::GetDirectInput();
	CInputKeyBoard *pKeyBoard = CManager::GetInputKeyboard();

	//A�{�^����������
	if (pGamePad->GetButtonTrigger(XINPUT_GAMEPAD_A) == true ||
		pGamePad->GetButtonTrigger(XINPUT_GAMEPAD_START) == true||
		pDGamePad->GetButtonTrigger(CDirectInput::START)==true ||
		pKeyBoard->GetTrigger(DIK_SPACE) == true ||
		pKeyBoard->GetTrigger(DIK_RETURN) == true)
	{
		if (m_bNextMode == false)
		{
			CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_ENTER);
			CManager::GetSound()->ControllVoice(CSound::SOUND_LABEL_SE_ENTER, 0.6f);

			//�X�^�[�g�̈ʒu�ɃG�t�F�N�g�̔���
			CSetEffect::SetEffect(4, D3DXVECTOR3(SCREEN_WIDTH / 3.0f, SCREEN_HEIGHT / 2 + 200.0f, 0.0f), {});

			//�Q�[�����[�h�֍s��
			CFade::SetFade(CManager::MODE_GAME);
			////���ȏ�ʂ�Ȃ��悤�ɂ���
			m_bNextMode = true;

		}
	}

	// �J�E���g�𑝂₷
	m_nCount++;

	// �A���t�@�l��������(�����ɂ���)
	if (m_bAlpha == false)
	{
		if (m_nCount % 2 == 0)
		{
			m_nAlpha -= 15;
		}

		// �A���t�@�l��0�ȉ��Ȃ�l���Œ肷��
		if (m_nAlpha <= 0)
		{
			m_nCount = 0;
			m_nAlpha = 0;
			m_bAlpha = true;
		}
	}
	// �A���t�@�l���グ��(�s�����ɂ���)
	else if (m_bAlpha == true)
	{
		if (m_nCount % 2 == 0)
		{
			m_nAlpha += 15;
		}

		if (m_nAlpha >= 255)
		{
			m_nCount = 0;
			m_nAlpha = 255;
			m_bAlpha = false;
		}
	}

	if (m_Polygon[1] != NULL)
	{
		m_Polygon[1]->SetCol(D3DCOLOR_RGBA(255, 255, 255, m_nAlpha));
	}
}
//--------------------------------------------
//�`��
//--------------------------------------------
void CTitle::Draw(void)
{

}

