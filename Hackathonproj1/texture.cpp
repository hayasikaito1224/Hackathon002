//=============================================================================
//
// �e�N�X�`������ [texture.cpp]
// Author : �H�������
//
//=============================================================================
//=============================================================================
// �C���N���[�h
//=============================================================================
#include "texture.h"
#include "Renderer.h"
#include "manager.h"

//=============================================================================
// �f�t�H���g�R���X�g���N�^
//=============================================================================
CTexture::CTexture()
{

}

//=============================================================================
// �f�t�H���g�f�X�g���N�^
//=============================================================================
CTexture::~CTexture()
{

}

//=============================================================================
// �e�N�X�`���̐���
//=============================================================================
void CTexture::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�̃|�C���^
	pDevice = CManager::GetRenderer()->GetDevice();	//�f�o�C�X���擾����

	D3DXCreateTextureFromFile(pDevice,
		"",	// ����
		&m_pTexture[None]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/test_texture.png",//���e�N�X�`��
		&m_pTexture[Test]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/number.png",//�ԍ�
		&m_pTexture[Number]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Hukuro.png",//��
		&m_pTexture[Bag]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/BackGround.png",//�Q�[���w�i
		&m_pTexture[GameBg]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Hakari.png",//��
		&m_pTexture[Balance]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/black.png",//�t�F�[�h
		&m_pTexture[Fade]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/TitleLogo.png",//�^�C�g�����S
		&m_pTexture[TitleLogo]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/TitleEnter.png",//�^�C�g������
		&m_pTexture[TitleEnter]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/TitleBG.jpg",//�^�C�g���w�i
		&m_pTexture[TitleBG]);
}

//=============================================================================
// �I��
//=============================================================================
void CTexture::Uniinit(void)
{
	for (int nCntTexture = 0; nCntTexture < Max; nCntTexture++)
	{
		//�e�N�X�`���̔j��
		if (m_pTexture[nCntTexture] != NULL)
		{
			m_pTexture[nCntTexture]->Release();
			m_pTexture[nCntTexture] = NULL;
		}
	}
}