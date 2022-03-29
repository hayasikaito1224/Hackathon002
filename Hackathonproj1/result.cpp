//--------------------------------------
//リザルト画面の処理
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
#include "directinput.h"
CBg *CResult::m_pBg = NULL;
//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CResult::CResult()
{
	m_bNextMode = false;
	m_Cursol = NULL;
}
//--------------------------------------------
//デストラクタ
//--------------------------------------------
CResult::~CResult()
{
}
//--------------------------------------------
//初期化
//--------------------------------------------
HRESULT CResult::Init(void)
{
	m_bNextMode = false;
	//m_pBg = CBg::Create(CTexture::GameClear000, CScene::OBJTYPE_BG, false);	//背景
	//pPolygon[1] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 80.0f, 0.0f), D3DXVECTOR3(200, 40.0f, 0.0f), CTexture::Retry);	//リトライ
	//pPolygon[2] = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 200.0f, 0.0f), D3DXVECTOR3(200, 40.0f, 0.0f), CTexture::TitleBack001);	//タイトルに戻る
	//m_Cursol = CPolygon::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 200.0f, 0.0f), D3DXVECTOR3(50.0f, 50.0f, 0.0f), CTexture::Cursol);	//タイトルに戻る
																																							//m_pBg->SetCol(D3DXCOLOR(0.0, 0.0, 1.0, 1.0));

	return S_OK;
}
//--------------------------------------------
//終了
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
	if (m_Cursol != NULL)
	{
		m_Cursol->Uninit();
		m_Cursol = NULL;
	}
}
//--------------------------------------------
//更新
//--------------------------------------------
void CResult::Update(void)
{

	CXInput *pGamePad = CManager::GetXInput();
	CInputKeyBoard *pKeyBoard = CManager::GetInputKeyboard();

	//Aボタンを押すと
	if (pGamePad->GetButtonTrigger(XINPUT_GAMEPAD_A) == true ||
		pKeyBoard->GetTrigger(DIK_SPACE) == true ||
		pKeyBoard->GetTrigger(DIK_RETURN) == true)
	{
		if (m_bNextMode == false)
		{
			CManager::GetSound()->PlaySoundA(CSound::SOUND_LABEL_SE_ENTER);
			CManager::GetSound()->ControllVoice(CSound::SOUND_LABEL_SE_ENTER, 0.6f);

			//タイトルへ行く
			CFade::SetFade(CManager::MODE_TITLE);
			////二回以上通らないようにする
			m_bNextMode = true;
		}
	}
}
//--------------------------------------------
//描画
//--------------------------------------------

void CResult::Draw(void)
{

}

