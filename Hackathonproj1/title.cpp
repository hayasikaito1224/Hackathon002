//--------------------------------------
//マネージャーの処理
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

//エフェクト
#include "SetEffect.h"

//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CTitle::CTitle()
{
	memset(&m_Polygon, NULL, sizeof(m_Polygon));
	m_bOpra = false;
}
//--------------------------------------------
//デストラクタ
//--------------------------------------------
CTitle::~CTitle()
{

}

//--------------------------------------------
//初期化
//--------------------------------------------
HRESULT CTitle::Init(void)
{
	m_bNextMode = false;
	m_nCount = 0;
	m_bAlpha = false;
	m_nAlpha = 255;
	CBg::Create(CTexture::TitleBG, CScene::OBJTYPE_BG, false);	//背景
	
	m_Polygon[0] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH/3.0f, SCREEN_HEIGHT / 2 - 100.0f, 0.0f), D3DXVECTOR3(340.0f, 200.0f, 0.0f), CTexture::TitleLogo);	//タイトルロゴ
	
	m_Polygon[1] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH/3.0f, SCREEN_HEIGHT / 2 + 200.0f, 0.0f), D3DXVECTOR3(280.0f, 50.0f, 0.0f), CTexture::TitleEnter);	//エンター文字

	m_Polygon[2] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 5.0f * 4, SCREEN_HEIGHT / 2.0f, 0.0f), D3DXVECTOR3(220.0f, 280.0f, 0.0f), CTexture::Rule);	//ルール

	return S_OK;
}
//--------------------------------------------
//終了
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
//更新
//--------------------------------------------
void CTitle::Update(void)
{
	CXInput *pGamePad = CManager::GetXInput();
	CDirectInput *pDGamePad = CManager::GetDirectInput();
	CInputKeyBoard *pKeyBoard = CManager::GetInputKeyboard();

	//Aボタンを押すと
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

			//スタートの位置にエフェクトの発生
			CSetEffect::SetEffect(4, D3DXVECTOR3(SCREEN_WIDTH / 3.0f, SCREEN_HEIGHT / 2 + 200.0f, 0.0f), {});

			//ゲームモードへ行く
			CFade::SetFade(CManager::MODE_GAME);
			////二回以上通らないようにする
			m_bNextMode = true;

		}
	}

	// カウントを増やす
	m_nCount++;

	// アルファ値を下げる(透明にする)
	if (m_bAlpha == false)
	{
		if (m_nCount % 2 == 0)
		{
			m_nAlpha -= 15;
		}

		// アルファ値が0以下なら値を固定する
		if (m_nAlpha <= 0)
		{
			m_nCount = 0;
			m_nAlpha = 0;
			m_bAlpha = true;
		}
	}
	// アルファ値を上げる(不透明にする)
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
//描画
//--------------------------------------------
void CTitle::Draw(void)
{

}

