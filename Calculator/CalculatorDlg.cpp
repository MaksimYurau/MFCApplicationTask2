#include "stdafx.h"
#include <string>
#include <sstream>
#include "CalculatorApp.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_output(_T(""))
	, m_historyText(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_historyBkColor = RGB(0, 0, 166); 
	m_historyBkBrush = std::make_unique<CBrush>(m_historyBkColor);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_output);
	DDX_Control(pDX, IDC_EDIT_RESULT, m_editResult);
	DDX_Control(pDX, IDC_BUTTON_0, m_button0);
	DDX_Control(pDX, IDC_BUTTON_1, m_button1);
	DDX_Control(pDX, IDC_BUTTON_2, m_button2);
	DDX_Control(pDX, IDC_BUTTON_3, m_button3);
	DDX_Control(pDX, IDC_BUTTON_4, m_button4);
	DDX_Control(pDX, IDC_BUTTON_5, m_button5);
	DDX_Control(pDX, IDC_BUTTON_6, m_button6);
	DDX_Control(pDX, IDC_BUTTON_7, m_button7);
	DDX_Control(pDX, IDC_BUTTON_8, m_button8);
	DDX_Control(pDX, IDC_BUTTON_9, m_button9);
	DDX_Control(pDX, IDC_BUTTON_PLUS, m_buttonPlus);
	DDX_Control(pDX, IDC_BUTTON_EQUALS, m_buttonEquals);
	DDX_Control(pDX, IDC_BUTTON_C, m_buttonC);
	DDX_Control(pDX, IDC_BUTTON_MINUS, m_buttonMinus);
	DDX_Control(pDX, IDC_BUTTON_MULTIPLY, m_buttonMultiply);
	DDX_Control(pDX, IDC_BUTTON_DIVIDE, m_buttonDivide);
	DDX_Control(pDX, IDC_EDIT_HISTORY, m_editHistory);
	DDX_Text(pDX, IDC_EDIT_HISTORY, m_historyText);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_EQUALS, &CCalculatorDlg::OnBnClickedButtonEquals)
	ON_BN_CLICKED(IDC_BUTTON_C, &CCalculatorDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CCalculatorDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculatorDlg::OnBnClickedButtonMinus)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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


	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		

	m_font.CreateFont(32, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 
		0, 0, 0, 0, _T("Microsoft Sans Serif"));
	m_historyFont.CreateFont(18, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET,
		0, 0, 0, 0, _T("Microsoft Sans Serif"));
	m_editResult.SetFont(&m_font);
	m_button0.SetFont(&m_font);
	m_button1.SetFont(&m_font);
	m_button2.SetFont(&m_font);
	m_button3.SetFont(&m_font);
	m_button4.SetFont(&m_font);
	m_button5.SetFont(&m_font);
	m_button6.SetFont(&m_font);
	m_button7.SetFont(&m_font);
	m_button8.SetFont(&m_font);
	m_button9.SetFont(&m_font);
	m_buttonPlus.SetFont(&m_font);
	m_buttonC.SetFont(&m_font);
	m_buttonMinus.SetFont(&m_font);
	m_buttonMultiply.SetFont(&m_font);
	m_editHistory.SetFont(&m_historyFont);
	m_buttonDivide.SetFont(&m_font);
	m_buttonEquals.SetFont(&m_font);
	GetDlgItem(IDC_STATIC)->SetFont(&m_historyFont);
	reset();

	return TRUE;  
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalculatorDlg::reset()
{
	m_calculator.reset();
	m_errorInput = false;
	m_firstDigitEntered = FALSE;
	resetOutput();
	m_historyText = "";
	UpdateData(FALSE);
}

void CCalculatorDlg::resetOutput()
{
	m_output = m_outputResetString;
}

void CCalculatorDlg::addDigit(char digit)
{
	if (m_errorInput)
		return;

	UpdateData();

	if (m_calculator.isOperation(m_calculator.getLastInput().actionType)  &&
		!m_firstDigitEntered)
	{

		m_output = digit;
	}
	else
	{
		if (m_output == m_outputResetString && digit == '0')
			return; 
		else if (m_output == m_outputResetString)
			m_output = digit; 
		else
			m_output += digit;
	}

	m_firstDigitEntered = TRUE;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedButton0()
{
	addDigit('0');
}

void CCalculatorDlg::OnBnClickedButton1()
{
	addDigit('1');
}

void CCalculatorDlg::OnBnClickedButton2()
{
	addDigit('2');
}

void CCalculatorDlg::OnBnClickedButton3()
{
	addDigit('3');
}

void CCalculatorDlg::OnBnClickedButton4()
{
	addDigit('4');
}

void CCalculatorDlg::OnBnClickedButton5()
{
	addDigit('5');
}

void CCalculatorDlg::OnBnClickedButton6()
{
	addDigit('6');
}

void CCalculatorDlg::OnBnClickedButton7()
{
	addDigit('7');
}

void CCalculatorDlg::OnBnClickedButton8()
{
	addDigit('8');
}

void CCalculatorDlg::OnBnClickedButton9()
{
	addDigit('9');
}

void CCalculatorDlg::createHistoryText()
{
	m_historyText = "";
	int historySize = m_calculator.getActionsSize();
	for (int i = 0; i < historySize; ++i)
	{
		switch (m_calculator.getAction(i).actionType)
		{
		case Calculator::ActionType::Number:
			{
				CString strNumber;
				std::stringstream ss;
				ss << m_calculator.getAction(i).value;
				std::string stdNum = ss.str();

				strNumber = stdNum.c_str();
				if(m_historyText.IsEmpty())
					m_historyText += strNumber;
				else
					m_historyText += (CString(" ") + strNumber);
			}
			break;
		case Calculator::ActionType::Plus:
			m_historyText += " +";
			break;
		case Calculator::ActionType::Divide:
			m_historyText += " /";
			break;
		case Calculator::ActionType::Minus:
			m_historyText += " -";
			break;
		case Calculator::ActionType::Multiply:
			m_historyText += " x";
			break;
		case Calculator::ActionType::Equals:
			m_historyText += " =";
			break;
		case Calculator::ActionType::None:
			break;
		}
	}
}

void CCalculatorDlg::doOperation(Calculator::ActionType operation, bool handleNumber)
{
	if (m_errorInput)
		return;

	UpdateData();
	Calculator::Action input;
	if (handleNumber)
	{
		input.actionType = Calculator::ActionType::Number;
		input.value = _wtof(m_output);
		m_calculator.addInput(input);
	}

	input.actionType = operation;
	m_errorInput = false;
	try
	{

		if (m_calculator.addInput(input))
		{

			if (!m_calculator.hasLeftTermValue() || !m_calculator.hasLeftExpressionValue())
			{
		
				std::stringstream ss;
				ss << m_calculator.getCurrentResult();
				std::string curResult = ss.str();

				m_output = "";
				m_output += curResult.c_str();
				UpdateData(FALSE);
			}
		}
		else 
			AfxMessageBox(_T("Error: An unknown operation.")); 
	}
	catch (std::exception& e)
	{

		m_output = e.what();
		m_firstDigitEntered = FALSE;
		m_errorInput = true;
	}

	createHistoryText();
	if (operation == Calculator::ActionType::Equals)
	{
		if (m_errorInput)
			m_historyText += " ";
		m_historyText += m_output;
	}
	UpdateData(FALSE);
	m_firstDigitEntered = FALSE;
}

void CCalculatorDlg::OnBnClickedButtonPlus()
{
	doOperation(Calculator::ActionType::Plus);
}

void CCalculatorDlg::OnBnClickedButtonEquals()
{
	doOperation(Calculator::ActionType::Equals);
}

void CCalculatorDlg::OnBnClickedButtonC()
{
	reset();
}

void CCalculatorDlg::OnBnClickedButtonDivide()
{
	doOperation(Calculator::ActionType::Divide);
}

void CCalculatorDlg::OnBnClickedButtonMultiply()
{
	doOperation(Calculator::ActionType::Multiply);
}

void CCalculatorDlg::OnBnClickedButtonMinus()
{
	doOperation(Calculator::ActionType::Minus);
}

HBRUSH CCalculatorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);


	switch (nCtlColor) {
	case CTLCOLOR_EDIT:
		if (pWnd->GetDlgCtrlID() == IDC_EDIT_HISTORY)
		{
			pDC->SetTextColor(RGB(0, 255, 0));
			pDC->SetBkColor(m_historyBkColor);
			return (HBRUSH)(m_historyBkBrush->GetSafeHandle());
		}
	}

	return hbr;
}

