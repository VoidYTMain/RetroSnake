#pragma once

#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED

#include <windows.h>
#include <Windows.h>
#include <time.h>
#include "GameColor.hpp"

constexpr auto GAME_NAME = "̰���ߴ���ս(Console Version) by ������";
constexpr auto GAME_VERSION = "Version 0.7.4";

constexpr auto WIN_HEIGHT = 43;
constexpr auto WIN_WIDTH = 120;
constexpr auto GAME_HEIGHT = 40;
constexpr auto GAME_WIDTH = 40;
constexpr auto MSG_WIDTH = 20;
constexpr auto MSG_HEIGHT = 20;
constexpr auto MAZE_HEIGHT = 20;
constexpr auto MAZE_WIDTH = 20;

 /* ���ÿ���̨���ڱ��� */
void SetTitle(const char * title);
/* 0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
 * 8-��ɫ, 9-����ɫ, 10-����ɫ,   11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ
 */
void SetColor(Color);

/* ���ݿ�����ÿ���̨���ڵĴ�С */
void SetConsoleWindowSize();
void ResetCursor();
/* ���ù���x��y����-���������� */
void SetPosition(int x, int y);

/* ��̬��ӡ������Ϣ */
void PrintString(const char * msgString);

/* ����fgets, ��ȡ��Ӧ���ȵ��ַ���*/
void Read(char * Str, int BufferSize);

/* �õ��û�����ļ� */
int GetKey();

/* ����ʼ���꿪ʼ����rowCount�� */
void ClearByCoord(int x, int y, int rowCount);

#endif // GAMELIB_H_INCLUDED
