
// CALCULATORDlg.h : ͷ�ļ�
//

#pragma once


// CCALCULATORDlg �Ի���
class CCALCULATORDlg : public CDialogEx
{
// ����
public:
	CCALCULATORDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_str;
	double temp;
	int flag,flag2;
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDivision();
	afx_msg void OnBnClickedEqual();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedSquare();
	afx_msg void OnBnClickedGuanyu();
	afx_msg void OnBnClickedPlusorminus();
	afx_msg void OnBnClickedEvolution();
	afx_msg void OnBnClickedDenominator();
	afx_msg void OnBnClickedPercent();
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	double x,y;
	int m_h;
	int m_m;
	int m_s;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedCloc();
};
