//=============================================================================
// ���[�h�����鏈�� [Load.cpp]
// Author : �����G��
//=============================================================================
//*****************************************************************************
// �C���N���[�h�t�@�C��
//***************************************************************************** 
#include "LoadEffect.h"
#include "SetEffect.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CLoadEffect::CLoadEffect()
{

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CLoadEffect::~CLoadEffect()
{

}

//=============================================================================
// �G�t�F�N�g���̓ǂݍ���
//=============================================================================
void CLoadEffect::EffectStateLoad(const char *aFileName)
{
	FILE *pFile;
	pFile = fopen(aFileName, "r");
	char aFile[256];

	bool bEffectState2D = false;
	int nPattern = 0;
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Addmove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	int Diffusion = 1;
	int Destroyvec = 0;
	float fSize = 0;
	float fAddSize = 0;
	D3DCOLORVALUE col;
	D3DCOLORVALUE ChangeColor;
	int nLife = 0;
	int Density = 1;
	int bRandColR = false;
	int bRandColG = false;
	int bRandColB = false;
	int bMoveRandX = false;
	int bMoveRandY = false;
	int bMousePos = false;

	if (pFile != NULL)
	{
		while (true)
		{
			fscanf(pFile, "%s", &aFile[0]); //fscanf���J��Ԃ��ăt�@�C����ǂݎ���Ă���

			if (bEffectState2D == true)
			{
				if (strcmp(&aFile[0], "PATTERN") == 0)	//�����̃p�^�[��
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &nPattern);
				}
				if (strcmp(&aFile[0], "POS") == 0)	//�o���ʒu
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%f %f %f", &pos.x, &pos.y, &pos.z);
				}
				if (strcmp(&aFile[0], "MOVE") == 0)	//�ړ���
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%f %f %f", &move.x, &move.y, &move.z);
				}
				if (strcmp(&aFile[0], "ADDMOVE") == 0)	//�������Z
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%f %f %f", &Addmove.x, &Addmove.y, &Addmove.z);
				}
				if (strcmp(&aFile[0], "DIFFUSION") == 0)	//�g�U��
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &Diffusion);
				}
				if (strcmp(&aFile[0], "DESTROYVEC") == 0)	//������x�N�g��
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &Destroyvec);
				}
				if (strcmp(&aFile[0], "SIZE") == 0)	//�傫��
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%f", &fSize);
				}
				if (strcmp(&aFile[0], "ADDSIZE") == 0)	//�傫�����Z
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%f", &fAddSize);
				}
				if (strcmp(&aFile[0], "COLOR") == 0)	//�J���[
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%f %f %f %f", &col.r, &col.g, &col.b, &col.a);
				}
				if (strcmp(&aFile[0], "CHANGECOLOR") == 0)	//�J���[�ϓ�
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%f %f %f %f", &ChangeColor.r, &ChangeColor.g, &ChangeColor.b, &ChangeColor.a);
				}
				if (strcmp(&aFile[0], "LIFE") == 0)	//����
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &nLife);
				}
				if (strcmp(&aFile[0], "DENSITY") == 0)	//���x
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &Density);
				}
				if (strcmp(&aFile[0], "COLORRANDR") == 0)	//�J���[�����_����
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &bRandColR);
				}
				if (strcmp(&aFile[0], "COLORRANDG") == 0)	//�J���[�����_����
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &bRandColG);
				}
				if (strcmp(&aFile[0], "COLORRANDB") == 0)	//�J���[�����_����
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &bRandColB);
				}
				if (strcmp(&aFile[0], "MOVERANDX") == 0)	//�ړ������_��X
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &bMoveRandX);
				}
				if (strcmp(&aFile[0], "MOVERANDY") == 0)	//�ړ������_��Y
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &bMoveRandY);
				}
				if (strcmp(&aFile[0], "MOUSEPOS") == 0)		//�}�E�X�Ǐ](�v���C���[�Ǐ]��������)
				{
					fscanf(pFile, "%s", &aFile[0]);
					fscanf(pFile, "%d", &bMousePos);
				}
			}

			//�G�t�F�N�g���Z�b�g
			if (strcmp(&aFile[0], "EFFECTSTATE2D") == 0)
			{
				bEffectState2D = true;
			}
			if (strcmp(&aFile[0], "END_EFFECTSTATE2D") == 0)
			{
				bEffectState2D = false;
				CSetEffect::SetEffectState2D(nPattern,pos, move, Addmove, Diffusion, Destroyvec, fSize, fAddSize, col, ChangeColor, nLife, Density,
					bRandColR, bRandColG, bRandColB, bMoveRandX, bMoveRandY, bMousePos);
			}

			//�I���
			if (strcmp(&aFile[0], "END_SCRIPT") == 0)
			{
				break;
			}
		}
	}
	fclose(pFile);
	CSetEffect::ResetPattern();
}
