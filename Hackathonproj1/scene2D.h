//----------------------------------
//�|���S���̏���
//----------------------------------
#ifndef _SCENE2D_H
#define _SCENE2D_H
#include "main.h"
#include "scene.h"
#include "texture.h"

//�}�N����`
#define FVF_VERTEX_2D (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)


//*****************************************************************************
// �\���̒�`
//*****************************************************************************
typedef struct
{
	D3DXVECTOR3 pos;//���_���W
	float		rhw;//1.0f�ŌŒ�
	D3DCOLOR	col;//���_�J���[
	D3DXVECTOR2 tex;//�e�N�X�`�����W
} VERTEX_2D;
//------------------------------------------------------------------------------
//�N���X�̒�`
//------------------------------------------------------------------------------
class CScene2D : public CScene
{
public:
	CScene2D(OBJTYPE nPriority = OBJTYPE_NONE);
	~CScene2D();
	HRESULT Init(CTexture::Type type);
	HRESULT Init(void);

	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CScene2D *Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale, CTexture::Type texture = CTexture::Test,CScene::OBJTYPE type = CScene::OBJTYPE_NONE);
	void SetPos(D3DXVECTOR3 vtx0, D3DXVECTOR3 vtx1, D3DXVECTOR3 vtx2, D3DXVECTOR3 vtx3);//���_���W�̐ݒ�
	void SetPos(D3DXVECTOR3 pos, D3DXVECTOR3 scale);		//���_���W�̐ݒ�
	void BindTexture(CTexture::Type type);
	void SetTex(int nAnim,int nPartU);						//�e�N�X�`���̐ݒ�
	void SetTex(float fSpeedX, float fSpeedY);						//�e�N�X�`���̐ݒ�
	void SetTex(int nType, int nPattern, float fSize);
	void SetCol(D3DXCOLOR col);						//�e�N�X�`���̐ݒ�
	void Rotate();//�|���S���̉�]����
	void Rotate(D3DXVECTOR3 pos, D3DXVECTOR3 scale);//�|���S���̉�]����
	void SetAngle(float fAngle) { m_fAngle = fAngle; }
	D3DXVECTOR3 GetRotatePos(int nVtx) { return m_rotatePos[nVtx]; }

	//�G�t�F�N�g
	void SetEffect(D3DXVECTOR3 pos) { m_EffectPos = pos; }
	D3DXVECTOR3 GetEffect() { return m_EffectPos; }
private:

protected:

	LPDIRECT3DTEXTURE9		m_pTexture;				//�e�N�X�`���ւ̃|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;				//���_�o�b�t�@�ւ̃|�C���^
	bool m_bUse;
	CTexture::Type			m_TexType;//�e�N�X�`���̃^�C�v
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_rotatePos[4];//��]���钸�_�̏��

	//�G�t�F�N�g
	D3DXVECTOR3 m_EffectPos;	//�G�t�F�N�g�̔����n�_

	D3DXVECTOR3 m_scale;
	D3DXCOLOR m_col;
	float m_fAngle;//�p�x
};


#endif // !_SCENE2D_H
