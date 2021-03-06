﻿// OprBtnHandle.cpp
//	
//	File thiết lập các hàm xử lý event
//	
//	khi người dùng nhấn nút dấu
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

////////////////////////////////////////////////
//
//	CÁCH THỨC HOẠT ĐỘNG
//
//	Khi người dùng nhấn nút dấu, active input sẽ được
//
//	đưa vào history và active input sẽ được reset về 0
//
////////////////////////////////////////////////

//Reset input screen & input memory
//Parameter:
//	- fullReset: reset về 0 hay hiện kết quả preCalc
void CCalculatorDlg::ResetInput(bool fullReset) 
{
	if (fullReset)
	{
		ActiveInput = "0";
		PassiveInput1 = "0";
		PassiveInput2 = "0";
		iInput = "0";
	}
	else
	{
		GetResultOutput();
		iInput = iOutput;
	}
}

//Lấy ký hiệu dấu
//Parameter
//- Opr: dấu cần lấy chuỗi ký hiệu
CString CCalculatorDlg::GetOprSymbol(char Opr)
{
	CString symbol;
	switch (Opr)
	{
	case '+':	//Plus
		symbol = '+';
		break;
	case '-':	//Minus
		symbol = '-';
		break;
	case '*':	//Multiply
		symbol = '×';
		break;
	case '/':	//Division
		symbol = '÷';
		break;
	case '&':	//And
		symbol = "AND";
		break;
	case '|':	//Or
		symbol = "OR";
		break;
	case '^':	//Xor
		symbol = "XOR";
		break;
	case '~':	//Not
		symbol = "NOT";
		break;
	case '<':	//Left Shift
		symbol = "ShiftL";
		break;
	case '>':	//Right Shift
		symbol = "ShiftR";
		break;
	case '[':	//Left Rotate
		symbol = "RotateL";
		break;
	case ']':	//Right Rotate
		symbol = "RotateR";
		break;
	case '=':
		symbol = "=";
	default:
		break;
	}
	return symbol;
}
/*
//Đưa active input vào history và tính toán
//Parameter:
//- Opr: ký tự dấu được đưa vào
void CCalculatorDlg::PushHistoryInput(char Opr)
{
	//Tạo dấu để đưa vào màn hình
	CString symbol, prevSymbol;
	symbol = GetOprSymbol(Opr);
	int prevSymbolLength = GetOprSymbol(prevOpr).GetLength();

	if (isEmptyInput == true)
	{
		//Nếu không input số thì chỉ sửa dấu
		hisActiveInput.Delete(hisActiveInput.GetLength() - prevSymbolLength, prevSymbolLength);
		hisPassiveInput1.Delete(hisPassiveInput1.GetLength() - prevSymbolLength, prevSymbolLength);
		hisPassiveInput2.Delete(hisPassiveInput2.GetLength() - prevSymbolLength, prevSymbolLength);
	}
	else
	{
		hisActiveInput += " ";
		hisPassiveInput1 += " ";
		hisPassiveInput2 += " ";

		//Đưa input vào history
		hisActiveInput += ActiveInput;
		hisPassiveInput1 += PassiveInput1;
		hisPassiveInput2 += PassiveInput2;

		hisActiveInput += " ";
		hisPassiveInput1 += " ";
		hisPassiveInput2 += " ";
	}

	//Đưa dấu vào history
	hisActiveInput += symbol;
	hisPassiveInput1 += symbol;
	hisPassiveInput2 += symbol;
}
*/

//Lấy active input ra và thực hiện tính toán
//Parameter
//- Opr: ký tự dấu được đưa vào
void CCalculatorDlg::PreCalc(char Opr)
{
	QInt temp1, temp;
	switch (Opr)
	{
	case '+':	//Plus
		temp = iOutput;
		iOutput = iOutput + iInput;
		//Nếu 2 số đầu vào cùng dấu mà ra kết quả trái dấu thì báo tràn
		if (!(temp.IsNegative()^iInput.IsNegative()) && (iOutput.IsNegative() ^ iInput.IsNegative()))
		{
			errorMessage = "Result Overflow";
		}
		break;
	case '-':	//Minus
		temp = iOutput;
		iOutput = iOutput - iInput;
		//Nếu 2 số đầu vào cùng dấu mà ra kết quả trái dấu thì báo tràn
		if (!(temp.IsNegative() ^ !iInput.IsNegative()) && (iOutput.IsNegative() ^ !iInput.IsNegative()))
		{
			errorMessage = "Result Overflow";
		}
		break;
	case '*':	//Multiply
		temp = iOutput;
		iOutput = iOutput * iInput;
		
		temp1 = iOutput / temp;
		//Nếu 1 số đầu vào khác 0 và kết quả chia số đó khác số còn lại => tràn
		if (!(temp == QInt("0")) && !((iOutput / temp) == iInput))
		{
			errorMessage = "Result Overflow";
		}
		break;
	case '/':	//Division
		iOutput = iOutput / iInput;
		if (iInput == QInt("0"))
			errorMessage = "Divide by 0";
		break;
	case '&':	//And
		iOutput = iOutput & iInput;
		break;
	case '|':	//Or
		iOutput = iOutput | iInput;
		break;
	case '^':	//Xor
		iOutput = iOutput ^ iInput;
		break;
	case '~':	//Not
		//Có hàm xử lý riêng
		break;
	case '<':	//Left Shift
		iOutput = iOutput << iInput;
		break;
	case '>':	//Right Shift
		iOutput = iOutput >> iInput;
		break;
	case '[':	//Left Rotate
		iOutput = iOutput.RotateLeft(iInput);
		break;
	case ']':	//Right Rotate
		iOutput = iOutput.RotateRight(iInput);
		break;
	case '=':	//Calc
		//Bấm calc thì có kết quả rồi nên không cần làm gì
		break;
	default:	//Không phát hiện dấu trước đó (aka số đầu tiên)
		iOutput = iInput;
		break;
	}
}

//Handle chung cho các event nhấn nút Operator
//Parameter:
//- Opr: ký tự dấu được đưa vào
void CCalculatorDlg::HandleOprButton(char Opr)
{
	//PushHistoryInput(Opr);	//Cập nhật history

	if (isEmptyInput == false)
	{
		PreCalc(prevOpr);	//Tính toán các opr có trước (nếu có)
		ResetInput(0);
	}

	prevOpr = Opr;	//Đưa dấu vào hàng đợi
	isEmptyInput = true;
	UpdateDisplay();
}

void CCalculatorDlg::OnBnClickedBtndot()
{
	isEmptyInput = false;	//Đánh dấu đã nhận input số
	if (ActiveInput == "0" || isEmptyInput)
	{
		ActiveInput = "0.";
	}
	else
	{
		for (int i = 0; i < ActiveInput.GetLength(); i++)
			if (ActiveInput[i] == _T('.'))
			{
				ActiveInput = ActiveInput.Left(i);
				UpdateDisplay();
				return;
			}
		ActiveInput += '.';
	}
	UpdateDisplay();
}

//Xử lý khi nhấn nút +
void CCalculatorDlg::OnBnClickedBtnplus()
{
	HandleOprButton('+');
}


void CCalculatorDlg::OnBnClickedBtnminus()
{
	HandleOprButton('-');
}


void CCalculatorDlg::OnBnClickedBtnmultiply()
{
	HandleOprButton('*');
}


void CCalculatorDlg::OnBnClickedBtndivision()
{
	HandleOprButton('/');
}


void CCalculatorDlg::OnBnClickedBtnand()
{
	HandleOprButton('&');
}


void CCalculatorDlg::OnBnClickedBtnor()
{
	HandleOprButton('|');
}


void CCalculatorDlg::OnBnClickedBtnxor()
{
	HandleOprButton('^');
}


void CCalculatorDlg::OnBnClickedBtnnot()
{
	//Nếu mới bấm calc xong thì sẽ reset lại về trạng thái đầu tiên 
	if (prevOpr == '=' && isEmptyInput)
	{
		prevOpr = NULL;
		iInput = iOutput;
		iOutput = "0";
	}

	//Phép not
	iInput = ~iInput;

	CString DecOutput;
	CString HexOutput;

	DecOutput = iInput.DecStr().c_str();
	HexOutput = iInput.HexStr().c_str();
	
	//Xuất input ra màn hình
	if (mode == 2)
	{
		ActiveInput = iInput.BinStr().c_str();
		PassiveInput1 = DecOutput;
		PassiveInput2 = HexOutput;
	}
	else if (mode == 10)
	{
		ActiveInput = DecOutput;
		PassiveInput1 = iInput.BinStr().c_str();
		PassiveInput2 = HexOutput;
	}
	else
	{
		ActiveInput = HexOutput;
		PassiveInput1 = iInput.BinStr().c_str();
		PassiveInput2 = DecOutput;
	}

	isEmptyInput = false;	//Đánh dấu đã nhận input số

	UpdateDisplay();
}


void CCalculatorDlg::OnBnClickedBtnrightsihft()
{
	HandleOprButton('>');
}


void CCalculatorDlg::OnBnClickedBtnleftshift()
{
	HandleOprButton('<');
}


void CCalculatorDlg::OnBnClickedBtnrolright()
{
	HandleOprButton(']');
}


void CCalculatorDlg::OnBnClickedBtnrolleft()
{
	HandleOprButton('[');
}