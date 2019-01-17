#pragma once

#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED

#include <windows.h>
#include <Windows.h>
#include <time.h>
#include "GameModel.hpp"

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

void ResetCursor();

// Function from http://www.xuetang9.com
 /* ���ÿ���̨���ڱ��� */
void SetTitle(const char * title);
/* 0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
 * 8-��ɫ, 9-����ɫ, 10-����ɫ,   11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ
 */
void SetColor(Color);

/* ���ݿ�����ÿ���̨���ڵĴ�С */
void SetConsoleWindowSize();
/* ���ù���x��y����-���������� */
void SetPosition(int x, int y);


#endif // GAMELIB_H_INCLUDED
