﻿
// CalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalculatorDlg dialog

CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, ActiveInput(_T(""))
	, PassiveInput1(_T(""))
	, PassiveInput2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ActiveInput);
	DDX_Text(pDX, IDC_EDIT2, PassiveInput1);
	DDX_Text(pDX, IDC_EDIT3, PassiveInput2);
	DDX_Control(pDX, BtnNum1, b_Num1);
	DDX_Control(pDX, BtnNum2, b_Num2);
	DDX_Control(pDX, BtnNum3, b_Num3);
	DDX_Control(pDX, BtnNum4, b_Num4);
	DDX_Control(pDX, BtnNum5, b_Num5);
	DDX_Control(pDX, BtnNum6, b_Num6);
	DDX_Control(pDX, BtnNum7, b_Num7);
	DDX_Control(pDX, BtnNum8, b_Num8);
	DDX_Control(pDX, BtnNum9, b_Num9);
	DDX_Control(pDX, BtnNum0, b_Num0);
	DDX_Control(pDX, BtnNumA, b_NumA);
	DDX_Control(pDX, BtnNumB, b_NumB);
	DDX_Control(pDX, BtnNumC, b_NumC);
	DDX_Control(pDX, BtnNumD, b_NumD);
	DDX_Control(pDX, BtnNumE, b_NumE);
	DDX_Control(pDX, BtnNumF, b_NumF);

	DDX_Control(pDX, BtnEqual, b_Equal);
	DDX_Control(pDX, BtnBackspace, b_Del);
	DDX_Control(pDX, BtnClear, b_Clear);
	DDX_Control(pDX, BtnDot, b_Dot);
	DDX_Control(pDX, BtnChangeSign, b_ChangeSign);

	DDX_Control(pDX, BtnPlus, b_oprPlus);
	DDX_Control(pDX, BtnMinus, b_oprMinus);
	DDX_Control(pDX, BtnMultiply, b_oprMultiply);
	DDX_Control(pDX, BtnDivision, b_oprDivision);

	DDX_Control(pDX, BtnAnd, b_oprAnd);
	DDX_Control(pDX, BtnOr, b_oprOr);
	DDX_Control(pDX, BtnXor, b_oprXor);
	DDX_Control(pDX, BtnNot, b_oprNot);
	DDX_Control(pDX, BtnRightShift, b_oprRightShift);
	DDX_Control(pDX, BtnLeftShift, b_oprLeftShift);
	DDX_Control(pDX, BtnRolLeft, b_oprLeftRol);
	DDX_Control(pDX, BtnRolRight, b_oprRightRol);

	DDX_Control(pDX, BtnBin, b_Passive1);
	DDX_Control(pDX, BtnHex, b_Passive2);
	DDX_Control(pDX, IDC_EDIT1, t_ActiveInput);
	DDX_Control(pDX, IDC_EDIT2, t_PassiveInput1);
	DDX_Control(pDX, IDC_EDIT3, t_PassiveInput2);
	DDX_Control(pDX, IDC_EDIT4, t_SignWarning);
	DDX_Control(pDX, IDC_RADIO1, r_IntMode);
	DDX_Control(pDX, IDC_RADIO2, r_FloatMode);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(BtnNum1, &CCalculatorDlg::OnBnClickedBtnnum1)
	ON_BN_CLICKED(BtnNum2, &CCalculatorDlg::OnBnClickedBtnnum2)
	ON_BN_CLICKED(BtnNum3, &CCalculatorDlg::OnBnClickedBtnnum3)
	ON_BN_CLICKED(BtnNum4, &CCalculatorDlg::OnBnClickedBtnnum4)
	ON_BN_CLICKED(BtnNum5, &CCalculatorDlg::OnBnClickedBtnnum5)
	ON_BN_CLICKED(BtnNum6, &CCalculatorDlg::OnBnClickedBtnnum6)
	ON_BN_CLICKED(BtnNum7, &CCalculatorDlg::OnBnClickedBtnnum7)
	ON_BN_CLICKED(BtnNum8, &CCalculatorDlg::OnBnClickedBtnnum8)
	ON_BN_CLICKED(BtnNum9, &CCalculatorDlg::OnBnClickedBtnnum9)
	ON_BN_CLICKED(BtnChangeSign, &CCalculatorDlg::OnBnClickedBtnchangesign)
	ON_BN_CLICKED(BtnNum0, &CCalculatorDlg::OnBnClickedBtnnum0)
	ON_BN_CLICKED(BtnDot, &CCalculatorDlg::OnBnClickedBtndot)
	ON_BN_CLICKED(BtnPlus, &CCalculatorDlg::OnBnClickedBtnplus)
	ON_BN_CLICKED(BtnMinus, &CCalculatorDlg::OnBnClickedBtnminus)
	ON_BN_CLICKED(BtnMultiply, &CCalculatorDlg::OnBnClickedBtnmultiply)
	ON_BN_CLICKED(BtnDivision, &CCalculatorDlg::OnBnClickedBtndivision)
	ON_BN_CLICKED(BtnEqual, &CCalculatorDlg::OnBnClickedBtnequal)
	ON_BN_CLICKED(BtnNumA, &CCalculatorDlg::OnBnClickedBtnnuma)
	ON_BN_CLICKED(BtnNumB, &CCalculatorDlg::OnBnClickedBtnnumb)
	ON_BN_CLICKED(BtnNumC, &CCalculatorDlg::OnBnClickedBtnnumc)
	ON_BN_CLICKED(BtnNumD, &CCalculatorDlg::OnBnClickedBtnnumd)
	ON_BN_CLICKED(BtnNumE, &CCalculatorDlg::OnBnClickedBtnnume)
	ON_BN_CLICKED(BtnNumF, &CCalculatorDlg::OnBnClickedBtnnumf)
	ON_BN_CLICKED(BtnAnd, &CCalculatorDlg::OnBnClickedBtnand)
	ON_BN_CLICKED(BtnOr, &CCalculatorDlg::OnBnClickedBtnor)
	ON_BN_CLICKED(BtnXor, &CCalculatorDlg::OnBnClickedBtnxor)
	ON_BN_CLICKED(BtnNot, &CCalculatorDlg::OnBnClickedBtnnot)
	ON_BN_CLICKED(BtnRightSihft, &CCalculatorDlg::OnBnClickedBtnrightsihft)
	ON_BN_CLICKED(BtnLeftShift, &CCalculatorDlg::OnBnClickedBtnleftshift)
	ON_BN_CLICKED(BtnRolRight, &CCalculatorDlg::OnBnClickedBtnrolright)
	ON_BN_CLICKED(BtnRolLeft, &CCalculatorDlg::OnBnClickedBtnrolleft)
	ON_BN_CLICKED(BtnBackspace, &CCalculatorDlg::OnBnClickedBtnbackspace)
	ON_BN_CLICKED(BtnClear, &CCalculatorDlg::OnBnClickedBtnclear)
	ON_BN_CLICKED(BtnHex, &CCalculatorDlg::OnBnClickedBtnPassive2)
	ON_BN_CLICKED(BtnBin, &CCalculatorDlg::OnBnClickedBtnPassive1)
	ON_EN_CHANGE(IDC_EDIT4, &CCalculatorDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_RADIO1, &CCalculatorDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CCalculatorDlg::OnBnClickedRadio2)
	ON_WM_DROPFILES()
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	ShowWindow(SW_NORMAL);

	// TODO: Add extra initialization here
	b_Dot.EnableWindow(0);

	b_NumFont.CreateFont(32, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Montserrat"));

	b_Num1.SetFont(&b_NumFont);
	b_Num2.SetFont(&b_NumFont);
	b_Num3.SetFont(&b_NumFont);
	b_Num4.SetFont(&b_NumFont);
	b_Num5.SetFont(&b_NumFont);
	b_Num6.SetFont(&b_NumFont);
	b_Num7.SetFont(&b_NumFont);
	b_Num8.SetFont(&b_NumFont);
	b_Num9.SetFont(&b_NumFont);
	b_Num0.SetFont(&b_NumFont);
	b_NumA.SetFont(&b_NumFont);
	b_NumB.SetFont(&b_NumFont);
	b_NumC.SetFont(&b_NumFont);
	b_NumD.SetFont(&b_NumFont);
	b_NumE.SetFont(&b_NumFont);
	b_NumF.SetFont(&b_NumFont);

	b_SymbolFont.CreateFont(36, 0, 0, 0, FW_LIGHT, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Times New Roman"));
	b_Equal.SetFont(&b_SymbolFont);
	b_ChangeSign.SetFont(&b_SymbolFont);
	b_Dot.SetFont(&b_SymbolFont);
	b_oprPlus.SetFont(&b_SymbolFont);
	b_oprMinus.SetFont(&b_SymbolFont);
	b_oprMultiply.SetFont(&b_SymbolFont);
	b_oprDivision.SetFont(&b_SymbolFont);

	b_TextOprFont.CreateFont(24, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Montserrat"));
	b_oprAnd.SetFont(&b_TextOprFont);
	b_oprOr.SetFont(&b_TextOprFont);
	b_oprXor.SetFont(&b_TextOprFont);
	b_oprNot.SetFont(&b_TextOprFont);
	b_oprLeftShift.SetFont(&b_TextOprFont);
	b_oprRightShift.SetFont(&b_TextOprFont);
	b_oprLeftRol.SetFont(&b_TextOprFont);
	b_oprRightRol.SetFont(&b_TextOprFont);
	b_Del.SetFont(&b_TextOprFont);
	b_Clear.SetFont(&b_TextOprFont);

	t_ActiveFont.CreateFont(65, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Montserrat"));
	t_PassiveFont.CreateFont(34, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Montserrat"));

	t_ActiveInput.SetFont(&t_ActiveFont);
	t_PassiveInput1.SetFont(&t_PassiveFont);
	t_PassiveInput2.SetFont(&t_PassiveFont);

	t_SignFont.CreateFont(24, 0, 0, 0, FW_LIGHT, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Montserrat"));

	t_SignWarning.SetFont(&t_SignFont);

	r_IntMode.SetCheck(1);
	ChangeMode_Dec();
	ResetInput(1);
	UpdateDisplay();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

//	Cập nhập tất cả display khi user nhấn nút số
void CCalculatorDlg::UpdateAllData() 
{
	ActiveInput.Remove(_T(' '));
	string ActiveInputString = (string)(CW2A(ActiveInput.GetString()));

	if (!(r_FloatMode.GetCheck()))
	{
		//Nếu đang ở QInt mode
		if (mode == 2)
		{
			//Thừa bit thì bỏ bit vừa thêm
			if (ActiveInputString.length() > 128)
			{
				PopInput();
				ActiveInputString = (string)(CW2A(ActiveInput.GetString()));
			}
			iInput = BinStrToDec(ActiveInputString);
			PassiveInput1 = iInput.DecStr().c_str();
			PassiveInput2 = iInput.HexStr().c_str();
		}
		else if (mode == 10)
		{
			iInput = ActiveInputString;
			//Nếu số chuyển đổi khác số ban đầu thì bỏ số vừa thêm
			if (ActiveInputString != iInput.DecStr())
			{
				PopInput();
				ActiveInputString = (string)(CW2A(ActiveInput.GetString()));
				iInput = ActiveInputString;
			}
			PassiveInput1 = iInput.BinStr().c_str();
			PassiveInput2 = iInput.HexStr().c_str();
		}
		else
		{
			iInput = HexToDec((char*)ActiveInputString.c_str());
			//Nếu số chuyển đổi khác số ban đầu thì bỏ số vừa thêm
			if (ActiveInputString != iInput.HexStr())
			{
				PopInput();
				ActiveInputString = (string)(CW2A(ActiveInput.GetString()));
				iInput = HexToDec((char*)ActiveInputString.c_str());
			}
			PassiveInput1 = iInput.BinStr().c_str();
			PassiveInput2 = iInput.DecStr().c_str();
		}
	}
	else 
	{
		if (mode == 2)
		{
			fInput = BinStrToDecF(ActiveInputString);
			ActiveInput = fInput.BinStr().c_str();
			PassiveInput1 = fInput.DecStr().c_str();
		}
		else
		{
			ReadDecString(ActiveInputString, fInput);
			ActiveInput = fInput.DecStr().c_str();
			PassiveInput1 = fInput.BinStr().c_str();
		}
	}
	UpdateDisplay();
}

//Cập nhật output hiển thị trên app
void CCalculatorDlg::UpdateDisplay()
{
	if (r_FloatMode.GetCheck())
		PassiveInput2 = "";	//Float mode không hỗ trợ xuất hex
	UpdateData(0);
	t_ActiveInput.SetSel(-1);
	t_PassiveInput1.SetSel(-1);
	t_PassiveInput2.SetSel(-1);
	//t_SignWarning.SetMargins(17, 0);
	
	//Nếu có thông báo lỗi thì in ra, không thì in dấu
	if (errorMessage == "")
		t_SignWarning.SetWindowText(GetOprSymbol(prevOpr));
	else
		t_SignWarning.SetWindowText(errorMessage);

	//Reset lỗi, nếu người dùng ignore và hết lỗi thì không báo nữa
	//Nhưng nếu vẫn lỗi thì hàm khác vẫn sẽ trả thông báo mới
	errorMessage = "";
}

//////////////////////////////////////////////////
//
//	Cách change mode hoạt động
//
//	Có 3 mode với 3 input được xếp thứ tự như sau
//	Dec: 10 -> 2 -> 16
//	Bin: 2 -> 10 -> 16
//	Hex: 16 -> 2 -> 10
//
//	Change mode sẽ activate/deactivate các nút bấm cho phù hợp 
//
//	và sắp xếp lại các input screen
//
///////////////////////////////////////////////////

//Thiết lập input thập phân
void CCalculatorDlg::ChangeMode_Dec() 
{
	if (r_FloatMode.GetCheck() == 1)
		b_Dot.EnableWindow(1);
	else
		b_Dot.EnableWindow(0);
	//Disable các nút input giá trị từ A - F và dot
	b_NumA.EnableWindow(0);
	b_NumB.EnableWindow(0);
	b_NumC.EnableWindow(0);
	b_NumD.EnableWindow(0);
	b_NumE.EnableWindow(0);
	b_NumF.EnableWindow(0);

	//Enable các nút input từ 2 - 9
	b_Num2.EnableWindow(1);
	b_Num3.EnableWindow(1);
	b_Num4.EnableWindow(1);
	b_Num5.EnableWindow(1);
	b_Num6.EnableWindow(1);
	b_Num7.EnableWindow(1);
	b_Num8.EnableWindow(1);
	b_Num9.EnableWindow(1);

	//Swap active input với dec input
	CString temp;
	if (mode == 2)
	{
		temp = ActiveInput;
		ActiveInput = PassiveInput1;
		PassiveInput1 = temp;

		b_Passive1.SetWindowText(_T("Binary"));
	}
	else
	{
		temp = ActiveInput;
		ActiveInput = PassiveInput2;
		PassiveInput2 = temp;

		b_Passive2.SetWindowText(_T("Hexadecimal"));
	}

	UpdateDisplay();
	mode = 10;
}


//Thiết lập input thập lục phân
void CCalculatorDlg::ChangeMode_Hex() 
{
	b_Dot.EnableWindow(0);

	//Enable tất cả các nút input
	b_NumA.EnableWindow(1);
	b_NumB.EnableWindow(1);
	b_NumC.EnableWindow(1);
	b_NumD.EnableWindow(1);
	b_NumE.EnableWindow(1);
	b_NumF.EnableWindow(1);
	b_Num2.EnableWindow(1);
	b_Num3.EnableWindow(1);
	b_Num4.EnableWindow(1);
	b_Num5.EnableWindow(1);
	b_Num6.EnableWindow(1);
	b_Num7.EnableWindow(1);
	b_Num8.EnableWindow(1);
	b_Num9.EnableWindow(1);

	//Swap active input với hex input
	CString temp;
	if (mode == 2)
	{
		//Nếu đang ở bin mode chuyển về dec mode
		temp = ActiveInput;
		ActiveInput = PassiveInput1;
		PassiveInput1 = temp;

		b_Passive1.SetWindowText(_T("Binary"));
	}

	//Từ dec chuyển về hex
	temp = ActiveInput;
	ActiveInput = PassiveInput2;
	PassiveInput2 = temp;

	b_Passive2.SetWindowText(_T("Decimal"));
	
	UpdateDisplay();
	mode = 16;
}


//Thiết lập input nhị phân
void CCalculatorDlg::ChangeMode_Bin() 
{
	b_Dot.EnableWindow(0);

	//Disable các nút input trừ nút 0 và 1
	b_NumA.EnableWindow(0);
	b_NumB.EnableWindow(0);
	b_NumC.EnableWindow(0);
	b_NumD.EnableWindow(0);
	b_NumE.EnableWindow(0);
	b_NumF.EnableWindow(0);
	b_Num2.EnableWindow(0);
	b_Num3.EnableWindow(0);
	b_Num4.EnableWindow(0);
	b_Num5.EnableWindow(0);
	b_Num6.EnableWindow(0);
	b_Num7.EnableWindow(0);
	b_Num8.EnableWindow(0);
	b_Num9.EnableWindow(0);

	//Swap active input với bin input
	CString temp;
	if (mode == 16)
	{
		//Nếu đang ở hex mode chuyển về dec mode
		temp = ActiveInput;
		ActiveInput = PassiveInput2;
		PassiveInput2 = temp;

		b_Passive2.SetWindowText(_T("Hexadecimal"));
	}

	//Từ dec chuyển về bin
	temp = ActiveInput;
	ActiveInput = PassiveInput1;
	PassiveInput1 = temp;
	
	b_Passive1.SetWindowText(_T("Decimal"));
	
	UpdateDisplay();
	mode = 2;
}


void CCalculatorDlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CCalculatorDlg::OnBnClickedRadio1()
{
	ChangeMode_Dec();
	t_ActiveInput.SetReadOnly(1);
	b_Passive2.EnableWindow(1);
	t_PassiveInput2.EnableWindow(1);
	b_oprAnd.EnableWindow(1);
	b_oprOr.EnableWindow(1);
	b_oprXor.EnableWindow(1);
	b_oprNot.EnableWindow(1);
	b_oprLeftShift.EnableWindow(1);
	b_oprRightShift.EnableWindow(1);
	b_oprLeftRol.EnableWindow(1);
	b_oprRightRol.EnableWindow(1);
	b_Equal.EnableWindow(1);
	b_oprPlus.EnableWindow(1);
	b_oprMinus.EnableWindow(1);
	b_oprMultiply.EnableWindow(1);
	b_oprDivision.EnableWindow(1);
	b_ChangeSign.EnableWindow(1);
	OnBnClickedBtnclear();
}


void CCalculatorDlg::OnBnClickedRadio2()
{
	ChangeMode_Dec();
	t_ActiveInput.SetReadOnly(0);
	b_Passive2.EnableWindow(0);
	t_PassiveInput2.EnableWindow(0);
	b_oprAnd.EnableWindow(0);
	b_oprOr.EnableWindow(0);
	b_oprXor.EnableWindow(0);
	b_oprNot.EnableWindow(0);
	b_oprLeftShift.EnableWindow(0);
	b_oprRightShift.EnableWindow(0);
	b_oprLeftRol.EnableWindow(0);
	b_oprRightRol.EnableWindow(0);
	b_ChangeSign.EnableWindow(0);

	b_oprPlus.EnableWindow(0);
	b_oprMinus.EnableWindow(0);
	b_oprMultiply.EnableWindow(0);
	b_oprDivision.EnableWindow(0);
	OnBnClickedBtnclear();
}


void CCalculatorDlg::OnDropFiles(HDROP hDropInfo)
{
	CString sInputFile;		//Đường dẫn của file được kéo thả vào
	CString sOutputFile;	//Đường dẫn của file output

	DWORD nBuffer = 0;

	//Lấy số lượng file được kéo thả vào
	UINT nFilesDropped = DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);
	
	//Nếu nhiều hơn 1 file thì chỉ lấy file đầu
	if (nFilesDropped > 0)
	{
		//Get the buffer size for the first filename
		nBuffer = DragQueryFile(hDropInfo, 0, NULL, 0);
		
		//Lấy đường dẫn
		DragQueryFile(hDropInfo, 0, sInputFile.GetBuffer(nBuffer + 1), nBuffer + 1);
		sInputFile.ReleaseBuffer();

		//Tách riêng đường dẫn thư mục
		int len = sInputFile.GetLength() - 1;
		while (sInputFile[len] != '\\')
			len--;
		len++;
		sOutputFile = sInputFile.Left(len) + _T("output.txt");

		//Xử lý file input
		if (r_FloatMode.GetCheck())
			ReadFileF((string)(CW2A(sInputFile)), (string)(CW2A(sOutputFile)));
		else
			ReadFile((string)(CW2A(sInputFile)), (string)(CW2A(sOutputFile)));
		
		ShellExecute(0, 0, sOutputFile, 0, 0, SW_SHOW);	//Mở file output
	}

	// Free the memory block containing the dropped-file information
	DragFinish(hDropInfo);
}
