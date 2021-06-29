#include <afxwin.h>

//自定义框架类
class CMyFrameWnd :public CFrameWnd {
public:
	virtual LRESULT WindowProc(UINT msgID, WPARAM wParam, LPARAM);
};
//自定义应用程序类
class CMyWinApp :public CWinApp
{
public:
	/*CMyWinApp()
	{
	}*/
	virtual BOOL InitInstance();//此函数的this指针是&theApp

};
//对于MFC非常重要的全局对象
CMyWinApp theApp; 


BOOL CMyWinApp:: InitInstance() {
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(NULL, "MFCBase");
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

LRESULT CMyFrameWnd::WindowProc(UINT msgID, WPARAM wParam, LPARAM IParam){
	switch (msgID) {
	case WM_CREATE:
		AfxMessageBox("WM_CREATE消息被处理");
		break;
	}
	//调用父类的虚函数的原因：未重写的消息处理虚函数交由父类的虚函数处理，已重写的虚函数由派生类虚函数处理。
	return CFrameWnd::WindowProc(msgID, wParam, IParam);
 }
