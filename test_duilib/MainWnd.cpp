#include"MainWnd.h"

//ASCII

//xml�ļ���Ӧ��Ŀ¼
CDuiString MainWnd::GetSkinFolder()
{
	return _T("");
}

//xml�ļ�������
CDuiString MainWnd::GetSkinFile()
{
	return _T("MainWnd.xml");
}

//����������֣���ע�ᴰ��ʱ�����ṩ
LPCTSTR MainWnd::GetWindowClassName(void) const
{
	return _T("MainWnd");
}