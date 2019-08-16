#include"MainWnd.h"

//ASCII

//xml文件对应的目录
CDuiString MainWnd::GetSkinFolder()
{
	return _T("");
}

//xml文件的名字
CDuiString MainWnd::GetSkinFile()
{
	return _T("MainWnd.xml");
}

//窗口类的名字：在注册窗口时必须提供
LPCTSTR MainWnd::GetWindowClassName(void) const
{
	return _T("MainWnd");
}