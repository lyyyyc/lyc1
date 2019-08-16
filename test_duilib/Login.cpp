#include"Login.h"
#include"MainWnd.h"

CDuiString LoginWnd::GetSkinFolder()
{
	return _T("");
}

//xml�ļ�������
CDuiString LoginWnd::GetSkinFile()
{
	return _T("LoginWnd.xml");
}

//����������֣���ע�ᴰ��ʱ�����ṩ
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
			//MessageBox(NULL, _T("MIN"), _T("Cashier"), IDOK);�����ȡС����ť
			::SendMessage(m_hWnd,WM_SYSCOMMAND,SC_MINIMIZE,0);
		else if (strName == _T("BIN_CLOSE"))
			//MessageBox(NULL, _T("CLOSE"), _T("Cashier"), IDOK);�����ȡ�رհ�ť
			Close();
		else if (strName == _T("BIN_LOGIN"))
			//MessageBox(NULL, _T("LOGIN"), _T("Cashier"), IDOK);
			Login();
	}
}

void LoginWnd::Login()
{
	//�ӱ༭���л�ȡ�û���������
	CEditUI* pEditUserName = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_USER_NAME"));
	CDuiString strUserName = pEditUserName->GetText();
	CEditUI* pEditUserPassWord = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_USER_PASSWORD"));
	CDuiString strUserPassWord = pEditUserPassWord->GetText();
  
	if (strUserName.IsEmpty())
	{
		MessageBox(m_hWnd, _T("�������û���"), _T("Cashier"),IDOK);
		return;
	 }
	if (strUserPassWord.IsEmpty())
	{
		MessageBox(m_hWnd, _T("����������"), _T("Cashier"), IDOK);
		return;
	}

	//��ѯ���ݿ⣬�����û��Ƿ����



	//����������
	MainWnd mianWnd;
	mianWnd.Create(NULL, _T("MainWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	mianWnd.CenterWindow();
	mianWnd.ShowModal();

	//���ص�¼����
	ShowWindow(false);
}