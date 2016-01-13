
// CALCULATORDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CALCULATOR.h"
#include "CALCULATORDlg.h"
#include "afxdialogex.h"
#include "iostream"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCALCULATORDlg 对话框




CCALCULATORDlg::CCALCULATORDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCALCULATORDlg::IDD, pParent)
	, m_str(_T(""))
	, m_h(0)
	, m_m(0)
	, m_s(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCALCULATORDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT, m_str);
	DDX_Text(pDX, IDC_EDIT1, m_h);
	DDX_Text(pDX, IDC_EDIT2, m_m);
	DDX_Text(pDX, IDC_EDIT3, m_s);
}

BEGIN_MESSAGE_MAP(CCALCULATORDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CCALCULATORDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CCALCULATORDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CCALCULATORDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_0, &CCALCULATORDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_ADD, &CCALCULATORDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_MINUS, &CCALCULATORDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_MUL, &CCALCULATORDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIVISION, &CCALCULATORDlg::OnBnClickedDivision)
	ON_BN_CLICKED(IDC_EQUAL, &CCALCULATORDlg::OnBnClickedEqual)
	ON_BN_CLICKED(IDC_DOT, &CCALCULATORDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_CLEAR, &CCALCULATORDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_4, &CCALCULATORDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CCALCULATORDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CCALCULATORDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CCALCULATORDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CCALCULATORDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CCALCULATORDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_BACK, &CCALCULATORDlg::OnBnClickedBack)
	ON_BN_CLICKED(IDC_SQUARE, &CCALCULATORDlg::OnBnClickedSquare)
	ON_BN_CLICKED(IDC_GUANYU, &CCALCULATORDlg::OnBnClickedGuanyu)
	ON_BN_CLICKED(IDC_PLUSORMINUS, &CCALCULATORDlg::OnBnClickedPlusorminus)
	ON_BN_CLICKED(IDC_EVOLUTION, &CCALCULATORDlg::OnBnClickedEvolution)
	ON_BN_CLICKED(IDC_DENOMINATOR, &CCALCULATORDlg::OnBnClickedDenominator)
	ON_BN_CLICKED(IDC_PERCENT, &CCALCULATORDlg::OnBnClickedPercent)
//	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CLOC, &CCALCULATORDlg::OnBnClickedCloc)
END_MESSAGE_MAP()


// CCALCULATORDlg 消息处理程序

BOOL CCALCULATORDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetTimer(1,1000,NULL);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCALCULATORDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCALCULATORDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCALCULATORDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCALCULATORDlg::OnBnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedClear();
		UpdateData(false);
		flag2=0;
	}
	UpdateData(true);
	m_str=m_str+L"1";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedClear();
		UpdateData(false);
		flag2=0;
	}
	UpdateData(true);
	m_str=m_str+L"2";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedClear();
		UpdateData(false);
		flag2=0;
	}
	UpdateData(true);
	m_str=m_str+L"3";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedClear();
		UpdateData(false);
		flag2=0;
	}
	UpdateData(true);
	m_str=m_str+L"0";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);

}


void CCALCULATORDlg::OnBnClickedMinus()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedMul()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedDivision()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedEqual()
{
	// TODO: 在此添加控件通知处理程序代码
	TRACE(L"flag+%d",flag);
	UpdateData(true);
	if(flag==1)
	{ temp=temp+_ttof(m_str); }
	else
	{
		if(flag==2)
		{  temp=temp-_ttof(m_str); }
		else
		{
			if(flag==3)
		    {  temp=temp*_ttof(m_str); }
			else
			{
				if(flag==4)
		        {  temp=temp/_ttof(m_str); }
			}
		}

	}
	flag2=1;
	m_str.Format(L"%lf",temp);
	m_str.Right(1)=="0";
	m_str.Delete(m_str.GetAllocLength()-4,7);
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedDot()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(m_str.Find(L".")==-1)
	m_str=m_str+L".";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedClear()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str="";
	UpdateData(false);

}


void CCALCULATORDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedClear();
		UpdateData(false);
		flag2=0;
	}
	UpdateData(true);
	m_str=m_str+L"4";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedClear();
		UpdateData(false);
		flag2=0;
	}
	UpdateData(true);
	m_str=m_str+L"5";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedClear();
		UpdateData(false);
		flag2=0;
	}
	UpdateData(true);
	m_str=m_str+L"6";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedClear();
		UpdateData(false);
		flag2=0;
	}
	UpdateData(true);
	m_str=m_str+L"7";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedClear();
		UpdateData(false);
		flag2=0;
	}
	UpdateData(true);
	m_str=m_str+L"8";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	if(flag2==1)
	{
		OnBnClickedClear();
		UpdateData(false);
		flag2=0;
	}
	UpdateData(true);
	m_str=m_str+L"9";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedBack()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(!m_str.IsEmpty())
	{
		m_str=m_str.Left(m_str.GetLength()-1);
	}
	UpdateData(false);
	//hehe
}


void CCALCULATORDlg::OnBnClickedSquare()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str.Format(L"%lf",_ttof(m_str)*_ttof(m_str));
	m_str.Right(1)=="0";
	m_str.Delete(m_str.GetLength()-4,7);
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedGuanyu()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"杨20141105066");
}


void CCALCULATORDlg::OnBnClickedPlusorminus()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_str.Left(1)=="-")          
		m_str.Delete(0,1);
	else
		m_str=L"-"+m_str;
	UpdateData(false);

}


void CCALCULATORDlg::OnBnClickedEvolution()
{
	// TODO: 在此添加控件通知处理程序代码
	if(_ttof(m_str)<0)
	{
		OnBnClickedClear();
		MessageBox(L"错误");
	}
	temp=_ttof(m_str);
	double f =sqrt(temp);
	if(f-int(f)<=102000000)
	{
		m_str.Format(L"%d",(int)f);
	}
	else
	{
		m_str.Format(L"%d",f);
	}
	UpdateData(false);

}


void CCALCULATORDlg::OnBnClickedDenominator()
{
	// TODO: 在此添加控件通知处理程序代码
	if(_ttof(m_str)==0)
	{
		OnBnClickedClear();
		MessageBox(L"错误");
	}
	m_str.Format(L"%lf",1.0/_ttof(m_str));
	m_str.Right(1)=="0";
	m_str.Delete(m_str.GetAllocLength()-4,7);
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedPercent()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"我猜他不能用");
}


//void CCALCULATORDlg::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	TRACE("X=%d ,Y=%d\n",point.x,point.y);
//	CDialogEx::OnMouseMove(nFlags, point);
//}


void CCALCULATORDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int l1=70,l2=50,l3=30;
	CTime t=CTime::GetCurrentTime();
	m_h=t.GetHour();
	m_m=t.GetMinute();
	m_s=t.GetSecond();
	UpdateData(false);
	CDC *pdc;
	pdc=GetDC();
	pdc->SetWindowOrg(-520,-150);
	CPen *oldpen;
	CPen Pen(PS_SOLID,3,RGB(0,255,255));
	oldpen=pdc->SelectObject(&Pen);
	pdc->Ellipse(-100,100,100,-100);
	pdc->Ellipse(-3,-3,3,3);
	for(int i=0;i<12;i++)
	{
		double l=96,ag=i*3.14159/6;
		double a=l*sin(ag)+1,b=-l*cos(ag)+1,c=l*sin(ag)-1,d=-l*cos(ag)-1;
		pdc->Ellipse(a,b,c,d);
	}
	pdc->TextOutW(-8,-90,L"12");
	pdc->TextOutW(80,-8,L"3");
	pdc->TextOutW(-4,76,L"6");
	pdc->TextOutW(-86,-8,L"9");

	CPen whitepen(PS_SOLID,4,RGB(255,255,255));
	pdc->SelectObject(&whitepen);
	x=l1*sin(m_s*(3.1415926/30)-(3.1415926/30));
	y=l1*-cos(m_s*(3.1415926/30)-(3.1415926/30));
	pdc->MoveTo(0,0);
	pdc->LineTo(x,y);
	CPen pen1(PS_SOLID,2,RGB(255,0,0));
	pdc->SelectObject(&pen1);
	x=l1*sin(m_s*(3.1415926/30));
	y=l1*-cos(m_s*(3.1415926/30));
	pdc->MoveTo(0,0);
	pdc->LineTo(x,y);

	pdc->SelectObject(&whitepen);
	x=l2*sin(m_m*(3.1415926/30)+m_s*(3.1415926/1800));
	y=l2*-cos(m_m*(3.1415926/30)+m_s*(3.1415926/1800));
	pdc->MoveTo(0,0);
	pdc->LineTo(x,y);
	CPen pen2(PS_SOLID,2,RGB(0,255,0));
	pdc->SelectObject(&pen2);
	x=l2*sin(m_m*(3.1415926/30)+m_s*(3.1415926/1800));
	y=l2*-cos(m_m*(3.1415926/30)+m_s*(3.1415926/1800));
	pdc->MoveTo(0,0);
	pdc->LineTo(x,y);

	pdc->SelectObject(&whitepen);
	x=l3*sin(m_h*(3.1415926/6)+m_m*(3.1415926/360)+m_s*(3.1415926/21600));
	y=l3*-cos(m_h*(3.1415926/6)+m_m*(3.1415926/360)+m_s*(3.1415926/21600));
	pdc->MoveTo(0,0);
	pdc->LineTo(x,y);
	CPen pen3(PS_SOLID,2,RGB(0,0,255));
	pdc->SelectObject(&pen3);
    x=l3*sin(m_h*(3.1415926/6)+m_m*(3.1415926/360)+m_s*(3.1415926/21600));
	y=l3*-cos(m_h*(3.1415926/6)+m_m*(3.1415926/360)+m_s*(3.1415926/21600));
	pdc->MoveTo(0,0);
	pdc->LineTo(x,y);

	CDialogEx::OnTimer(nIDEvent);
}


void CCALCULATORDlg::OnBnClickedCloc()
{
	// TODO: 在此添加控件通知处理程序代码
	//SetTimer(1,1000,NULL);
}
