#include <afxwin.h>

//�Զ�������
class CMyFrameWnd :public CFrameWnd {
public:
	virtual LRESULT WindowProc(UINT msgID, WPARAM wParam, LPARAM);
};
//�Զ���Ӧ�ó�����
class CMyWinApp :public CWinApp
{
public:
	/*CMyWinApp()
	{
	}*/
	virtual BOOL InitInstance();//�˺�����thisָ����&theApp

};
//����MFC�ǳ���Ҫ��ȫ�ֶ���
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
		AfxMessageBox("WM_CREATE��Ϣ������");
		break;
	}
	//���ø�����麯����ԭ��δ��д����Ϣ�����麯�����ɸ�����麯����������д���麯�����������麯������
	return CFrameWnd::WindowProc(msgID, wParam, IParam);
 }
