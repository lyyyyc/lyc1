#include"Login.h"
#include"MainWnd.h"

CDuiString LoginWnd::GetSkinFolder()
{
	return _T("");
}

//xml文件的名字
CDuiString LoginWnd::GetSkinFile()
{
	return _T("LoginWnd.xml");
}

//窗口类的名字：在注册窗口时必须提供
LPCTSTR LoginWnd::GetWindowClassName(void) const
{
	return _T("LoginWnd");
}

void LoginWnd::Notify(TNotifyUI& msg)
{
	//m_PaintManager.FindControl(_T(""))
	CDuiString strName =msg.pSender->GetName();
	if (msg.sType == _T("click"))
	{
		if (strName == _T("BIN_MIN"))
			//MessageBox(NULL, _T("MIN"), _T("Cashier"), IDOK);检验获取小化按钮
			::SendMessage(m_hWnd,WM_SYSCOMMAND,SC_MINIMIZE,0);
		else if (strName == _T("BIN_CLOSE"))
			//MessageBox(NULL, _T("CLOSE"), _T("Cashier"), IDOK);检验获取关闭按钮
			Close();
		else if (strName == _T("BIN_LOGIN"))
			//MessageBox(NULL, _T("LOGIN"), _T("Cashier"), IDOK);
			Login();
	}
}

void LoginWnd::Login()
{
	//从编辑框中获取用户名和密码
	CEditUI* pEditUserName = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_USER_NAME"));
	CDuiString strUserName = pEditUserName->GetText();
	CEditUI* pEditUserPassWord = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_USER_PASSWORD"));
	CDuiString strUserPassWord = pEditUserPassWord->GetText();
  
	if (strUserName.IsEmpty())
	{
		MessageBox(m_hWnd, _T("请输入用户名"), _T("Cashier"),IDOK);
		return;
	 }
	if (strUserPassWord.IsEmpty())
	{
		MessageBox(m_hWnd, _T("请输入密码"), _T("Cashier"), IDOK);
		return;
	}

	//查询数据库，检测该用户是否存在



	//创建主窗口
	MainWnd mianWnd;
	mianWnd.Create(NULL, _T("MainWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	mianWnd.CenterWindow();
	mianWnd.ShowModal();

	//隐藏登录窗口
	ShowWindow(false);
}