//=============================================================================
//
// �e�N�X�`������ [texture.h]
// Author : �H������
//
//=============================================================================
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "main.h"

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CTexture
{
public:
	CTexture();	// �f�t�H���g�R���X�g���N�^
	~CTexture();// �f�t�H���g�f�X�g���N�^
	typedef enum
	{
		None = -1,		// �e�N�X�`������
		Test,			// ���e�N�X�`��
		Number,			// �ԍ�
		Bag,			// ��
		GameBg,			//�Q�[���̔w�i
		Balance,		//��
		Fade,			//�t�F�[�h
		TitleLogo,		// �^�C�g�����S
		TitleEnter,		// �^�C�g������
		TitleBG,		// �^�C�g���w�i
		Effect,			//�G�t�F�N�g�i���j
		Start,			// �X�^�[�g����
		Finish,			// �t�B�j�b�V������
		Rule,			// �^�C�g���ɕ\�����郋�[��
		Max,			// �e�N�X�`���̍ő吔
	} Type;

	void Init(void);	// �e�N�X�`���̐���
	LPDIRECT3DTEXTURE9 GetTexture(Type Type) { return m_pTexture[Type]; }	// �e�N�X�`���̊��蓖��(�e�N�X�`���̎��) { return �I�񂾃e�N�X�`����Ԃ� }
	void Uniinit(void);	// �I��

private:
	LPDIRECT3DTEXTURE9	m_pTexture[Max];	//�e�N�X�`��
};

#endif