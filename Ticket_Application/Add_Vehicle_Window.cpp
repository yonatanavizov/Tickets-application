// Add_Vehicle_Window.cpp : implementation file
//

#include "pch.h"
#include "Ticket_Application.h"
#include "Add_Vehicle_Window.h"
#include "afxdialogex.h"
#include "Boeing7371.h"
#include "GoldenQueen1.h"
#include "MAN_NL1.h"
#include "Taxi1.h"
#include "Train1.h"


int whichVehicleToCreate = 0;
// Add_Vehicle_Window dialog

IMPLEMENT_DYNAMIC(Add_Vehicle_Window, CDialogEx)

Add_Vehicle_Window::Add_Vehicle_Window(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Add_Vehicle, pParent)
{

}

Add_Vehicle_Window::~Add_Vehicle_Window()
{
}

void Add_Vehicle_Window::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, whichVehicleToCreate);
}




// Add_Vehicle_Window message handlers

BEGIN_MESSAGE_MAP(Add_Vehicle_Window, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Add_Vehicle_Window::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO2, &Add_Vehicle_Window::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &Add_Vehicle_Window::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &Add_Vehicle_Window::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &Add_Vehicle_Window::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO7, &Add_Vehicle_Window::OnBnClickedRadio7)
END_MESSAGE_MAP()


void Add_Vehicle_Window::OnBnClickedButton1()
{
	if (myVehicleArray.GetCount() == 18) // cant add vehicles
	{
		TRACE("\nToo much vehicles\n");
	}
	else // you can add vehicles
	{
		switch (whichVehicleToCreate)
		{
		case 1:
			dummyVehicle = new Taxi1();
			myVehicleArray.Add(dummyVehicle);
			break;
		case 2:
			dummyVehicle = new MAN_NL1();
			myVehicleArray.Add(dummyVehicle);
			break;
		case 3:
			dummyVehicle = new Train1();
			myVehicleArray.Add(dummyVehicle);
			break;
		case 4:
			dummyVehicle = new Boeing7371();
			myVehicleArray.Add(dummyVehicle);
			break;
		case 5:
			dummyVehicle = new GoldenQueen1();
			myVehicleArray.Add(dummyVehicle);
			break;
		default:
			break;
		}
		vehicleDlg.UpdateData(false);
	}
}


void Add_Vehicle_Window::OnBnClickedRadio2()
{
	
	whichVehicleToCreate = 1;
	UpdateData(false);
}


void Add_Vehicle_Window::OnBnClickedRadio3()
{
	whichVehicleToCreate = 2;
	UpdateData(false);
}


void Add_Vehicle_Window::OnBnClickedRadio4()
{
	whichVehicleToCreate = 3;
	UpdateData(false);
}


void Add_Vehicle_Window::OnBnClickedRadio5()
{
	whichVehicleToCreate = 4;
	UpdateData(false);
}


void Add_Vehicle_Window::OnBnClickedRadio7()
{
	whichVehicleToCreate = 5;
	UpdateData(false);
}

