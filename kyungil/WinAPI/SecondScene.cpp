#include "Stdafx.h"
#include "SecondScene.h"

HRESULT SecondScene::init(void)
{
	IMAGEMANAGER->addImage("������", "Resources/Images/BackGround/Repeating_BackGround.bmp", 1570, WINSIZE_Y);

	_offsetX = _offsetY = 0;
	_bgSpeed = 0;

	_ps = new PixelScene;
	_ps->init();

	_tempSound = new TempSoundScene;
	_tempSound->init();

	return S_OK;
}

void SecondScene::release(void)
{
	_ps->release();
	SAFE_DELETE(_tempSound);
}

void SecondScene::update(void)
{
	_bgSpeed += 3;
	_ps->update();
	_tempSound->update();
}

void SecondScene::render(void)
{
	IMAGEMANAGER->loopRender("������", getMemDC(),
		&RectMake(0, 0, WINSIZE_X, WINSIZE_Y), _bgSpeed, 0);

	//SetBkMode(): �����ϰ� ���ִ� �Լ�
	//�� ���� �ڷ� ����� ���̰� �Ѵ�.
	SetBkMode(getMemDC(), TRANSPARENT);

	char str[128];
	wsprintf(str, "���� ��Ʈ");
	TextOut(getMemDC(), 230, 350, str, strlen(str));

	HFONT font;
	HFONT oldFont;
	//�� H~ �� ������ �׷��ٳ��̶� ������ ���� �ʿ�

	/*
	font = CreateFont
	(
	1. ����ũ��, ������, ���� ����, ���� ����, ���� ����, 
	����(true, false), ����, ��Ҽ�, 
	2. ���� ����, ��� ��Ȯ��, Ŭ���� ��Ȯ��, ����� ��, �ڰ�, 3. ��Ʈ		
	)
	���ӿ����� 1, 2, 3 ���� �ַ� ���
	*/

	font = CreateFont
	(
		70, 0, 0, 0, 600,
		0, 0, 1,
		HANGUL_CHARSET, 0, 0, 0, 0, TEXT("�޸ձ���")
	);
	//HANGUL_CHARSET - ��Ƽ����Ʈ
	//HANGUEL_CHARSET - �����ڵ�

	oldFont = (HFONT)SelectObject(getMemDC(), font);

	wsprintf(str, "���ο� ��Ʈ");
	TextOut(getMemDC(), 100, 400, str, strlen(str));

	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);

	_ps->render();

}

/*
���� 1. ��Ʈ �Ŵ��� �ϼ�

- 3���� �Լ� ������ �ǵ��� �ʰ� (�߰� x, ���� x) ��� ������ �Ѵ�.
- ��µǴ� ������ ������ 3����
�� 1. ��ü ���۸� �о� �鿩�� �ٷ� ��µǴ� ���
�� 2. �ϳ��� ���۸� �о� �鿩�� ����ϴ� ���
�� 3. ��ŵ ����� �� ��� ���

�� ���Ǽ� + ȣȯ��


���� 2. ĳ���� ���� �� ���

- �ʼ�: �̹��� (���, ü�� ��, �÷��̾� (���, ����, ���), �� (���, ����, �ǰ�))
- �⺻������ ��������ó�� ��ġ (+ ü�¹�)
- �÷��̾� (1p) �� ���� �� �� �� �� �ְ� ���� ����ƺ�� �����Ѵ�.
�� ����ƺ�� ���� �� �ǰ� ����� �����Ѵ�.(+ ���)
- �÷��̾�� ��� ���� <-> ���� ���� On / Off ��ɸ� (�̵� x)
- ����, ���, �ǰ� ���� �߻��ϸ� ��Ȳ�� �´� ����� ȭ�鿡 ������
�� ����, ������, ġ��Ÿ ��
- �������� ǥ���Ѵ�.
*/