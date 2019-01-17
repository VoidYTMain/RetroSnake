#include "WindowsPath.hpp"

// Code from https://blog.csdn.net/zuishikonghuan/article/details/47441163

#include<windows.h>
//�򿪱����ļ��Ի���
#include<Commdlg.h>
//��ȡ���ҵ��ĵ���·��
#include <ShlObj.h>

inline string GetDocumentPath()
{
	char homePath[1024] = { 0 };
	SHGetSpecialFolderPath(nullptr, homePath, 5, false);
	return homePath;
}

inline void InitOFN(OPENFILENAME &ofn, string filter, string title)
{
	ofn.lStructSize = sizeof(OPENFILENAME);//�ṹ���С
	ofn.hwndOwner = NULL;//ӵ���Ŵ��ھ����ΪNULL��ʾ�Ի����Ƿ�ģ̬�ģ�ʵ��Ӧ����һ�㶼Ҫ��������
	ofn.lpstrFilter = TEXT(filter.c_str());//���ù���
	ofn.nFilterIndex = 1;//����������
	ofn.lpstrTitle = TEXT(title.c_str());//ʹ��ϵͳĬ�ϱ������ռ���
	ofn.lpstrInitialDir = GetDocumentPath().c_str();//��ʼĿ¼Ϊ�ҵ��ĵ�
}

string OpenFile(string filter)
{
	OPENFILENAME ofn = { 0 };
	InitOFN(ofn, filter, "��ѡ��һ���ļ�");

	TCHAR strFilename[MAX_PATH] = { 0 };//���ڽ����ļ���
	ofn.lpstrFile = strFilename;//���շ��ص��ļ�����ע���һ���ַ���ҪΪNULL
	ofn.nMaxFile = sizeof(strFilename);//����������

	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;//�ļ���Ŀ¼������ڣ�����ֻ��ѡ��

	while (!GetOpenFileName(&ofn))
		MessageBox(NULL, TEXT("��ѡ��һ���ļ�"), NULL, MB_ICONERROR);
	
	//MessageBox(NULL, strFilename, TEXT("ѡ����ļ�"), 0);
	return strFilename;
}

string SaveFile(string filter)
{
	OPENFILENAME ofn = { 0 };
	InitOFN(ofn, filter, "���浽");
	ofn.lpstrDefExt = TEXT("cpp");//Ĭ��׷�ӵ���չ��

	TCHAR strFilename[MAX_PATH] = { 0 };//���ڽ����ļ���
	ofn.lpstrFile = strFilename;//���շ��ص��ļ�����ע���һ���ַ���ҪΪNULL
	ofn.nMaxFile = sizeof(strFilename);//����������

	ofn.Flags = OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;//Ŀ¼������ڣ������ļ�ǰ��������

	while (!GetSaveFileName(&ofn))
		MessageBox(NULL, TEXT("������һ���ļ���"), NULL, MB_ICONERROR);
	
	//MessageBox(NULL, strFilename, TEXT("���浽"), 0);
	return strFilename;
}