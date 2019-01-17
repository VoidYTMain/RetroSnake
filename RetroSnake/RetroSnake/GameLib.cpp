#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdarg.h>
#include "GameLib.hpp"

/* ���ÿ���̨���ڱ��� */
void SetTitle(const char * title) {
	SetConsoleTitle(title);
}
/* 0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
 * 8-��ɫ, 9-����ɫ, 10-����ɫ,   11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ*/
void SetColor(Color color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                    //��ȡ��ǰ���ھ��
	SetConsoleTextAttribute(handle, short(color.fore) + short(color.back) * 0x10);//������ɫ
	//CloseHandle(handle);
}
/* ���ݿ�����ÿ���̨���ڵĴ�С */
void SetConsoleWindowSize() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ÿ���̨���ڵĻ�������С
	COORD size = { WIN_WIDTH, WIN_HEIGHT };
	SetConsoleScreenBufferSize(handle, size);
	//���ÿ���̨���ڴ�С,��������ǻ�������С-1
	SMALL_RECT rect = { 0, 0, WIN_WIDTH - 1, WIN_HEIGHT - 1 };
	SetConsoleWindowInfo(handle, 1, &rect);
	//CloseHandle(handle);
}
void ResetCursor()
{
	keybd_event(VK_SHIFT, 0, 0, 0);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
	CONSOLE_CURSOR_INFO cci;                    //����̨�����Ϣ�ṹ����
	cci.dwSize = 1;                             //����С
	cci.bVisible = FALSE;                       //�Ƿ���ʾ���
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cci);      //����ָ������̨��Ļ����������С�Ϳɼ���
}
void SetPosition(int x, int y) {
	COORD cursorPosition;   //��������
	HANDLE handle;          //��ǰ���ھ��
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cursorPosition.X = x*2;   //����x��y����
	cursorPosition.Y = y;
	SetConsoleCursorPosition(handle, cursorPosition);
	//CloseHandle(handle);
}
