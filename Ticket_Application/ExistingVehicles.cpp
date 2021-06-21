// ExistingVehicles.cpp : implementation file
//

#include "pch.h"
#include "Ticket_Application.h"
#include "ExistingVehicles.h"
#include "afxdialogex.h"
#include "Add_Vehicle_Window.h"
#include "deleteVehicleDlg.h"



// ExistingVehicles dialog

IMPLEMENT_DYNAMIC(ExistingVehicles, CDialogEx)

ExistingVehicles::ExistingVehicles(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

ExistingVehicles::~ExistingVehicles()
{
}

void ExistingVehicles::DoDataExchange(CDataExchange* pDX)
{
	CString objName2;
	int id;
	int i;

	for (i = 0; i < myVehicleArray.GetCount(); i++)
	{
		objName2 = myVehicleArray[i]->getNickName();
		id = myVehicleArray[i]->getID();
		CDialogEx::DoDataExchange(pDX);
		DDX_Text(pDX, Vehicle_Name_24 +i, objName2);
		DDX_Text(pDX, IDC_EDIT27 + i, id);
	}
	
	if ((Vehicle_Name_24 + myVehicleArray.GetCount()) <= (Vehicle_Name_41))
	{
		for (i = (Vehicle_Name_24 + myVehicleArray.GetCount()); i <= Vehicle_Name_41; i++)
		{
			objName2 = _T("No Vehicle.");
			DDX_Text(pDX, i, objName2);
		}
	}

	int pos = myVehicleArray.GetCount();
	DDX_Text(pDX, IDC_EDIT23, pos);
}


BEGIN_MESSAGE_MAP(ExistingVehicles, CDialogEx)
	ON_BN_CLICKED(IDOK, &ExistingVehicles::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON19, &ExistingVehicles::OnBnClickedButton19)
END_MESSAGE_MAP()


// ExistingVehicles message handlers


void ExistingVehicles::OnBnClickedOk()
{
	Add_Vehicle_Window vehicleDlg;
	vehicleDlg.DoModal();
}

void ExistingVehicles::OnBnClickedButton19()
{
	deleteVehicleDlg deleteWindow;
	deleteWindow.DoModal();
}
