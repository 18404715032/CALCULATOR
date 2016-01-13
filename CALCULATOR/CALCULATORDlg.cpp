
// CALCULATORDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCALCULATORDlg �Ի���




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


// CCALCULATORDlg ��Ϣ�������

BOOL CCALCULATORDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetTimer(1,1000,NULL);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCALCULATORDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCALCULATORDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCALCULATORDlg::OnBnClicked1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);

}


void CCALCULATORDlg::OnBnClickedMinus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedMul()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedDivision()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedEqual()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(m_str.Find(L".")==-1)
	m_str=m_str+L".";
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_str="";
	UpdateData(false);

}


void CCALCULATORDlg::OnBnClicked4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_str.Format(L"%lf",_ttof(m_str)*_ttof(m_str));
	m_str.Right(1)=="0";
	m_str.Delete(m_str.GetLength()-4,7);
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedGuanyu()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(L"��20141105066");
}


void CCALCULATORDlg::OnBnClickedPlusorminus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_str.Left(1)=="-")          
		m_str.Delete(0,1);
	else
		m_str=L"-"+m_str;
	UpdateData(false);

}


void CCALCULATORDlg::OnBnClickedEvolution()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(_ttof(m_str)<0)
	{
		OnBnClickedClear();
		MessageBox(L"����");
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(_ttof(m_str)==0)
	{
		OnBnClickedClear();
		MessageBox(L"����");
	}
	m_str.Format(L"%lf",1.0/_ttof(m_str));
	m_str.Right(1)=="0";
	m_str.Delete(m_str.GetAllocLength()-4,7);
	UpdateData(false);
}


void CCALCULATORDlg::OnBnClickedPercent()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(L"�Ҳ���������");
}


//void CCALCULATORDlg::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	TRACE("X=%d ,Y=%d\n",point.x,point.y);
//	CDialogEx::OnMouseMove(nFlags, point);
//}


void CCALCULATORDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//SetTimer(1,1000,NULL);
}
