//--------------------------------------
//ゲーム画面の処理
//--------------------------------------
#include "hide.h"
#include "Polygon.h"

#define HIDE_SCALE_X (170.0f)
#define HIDE_SCALE_Y (60.0f)
#define HIDE_POS_X (SCREEN_WIDTH / 2.0f-40.0f)

#define HIDE_MOVESTOP (570.0f)
#define HIDE_MOVE_SPEED (4.0f)

//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CHide::CHide()
{
	m_Hide = nullptr;
	m_bUp = false;
	m_bDown = false;
	m_bBase = false;
}
//--------------------------------------------
//デストラクタ
//--------------------------------------------
CHide::~CHide()
{
}
//--------------------------------------------
//初期化
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
//終了
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
//更新
//--------------------------------------------
void CHide::Update()
{
	//上がる判定がオンなら画像を上げる
	if (m_bUp==true)
	{
		UpMove();
	}
	//下がる判定がオンなら画像を下げる
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
//描画
//--------------------------------------------
void CHide::Draw()
{

}
//--------------------------------------------
//インスタンス生成
//--------------------------------------------

CHide * CHide::Create()
{
	//インスタンス生成
	CHide *pHide = new CHide;
	if (pHide != NULL)
	{
		pHide->Init();
	}
	return pHide;

}
//--------------------------------------------
//画像を上げる処理
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
//画像を下げる処理
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

