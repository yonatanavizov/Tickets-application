// deleteVehicleDlg.cpp : implementation file
//

#include "pch.h"
#include "Ticket_Application.h"
#include "deleteVehicleDlg.h"
#include "afxdialogex.h"


// deleteVehicleDlg dialog

IMPLEMENT_DYNAMIC(deleteVehicleDlg, CDialogEx)

deleteVehicleDlg::deleteVehicleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(delete_Vehicle, pParent)
	, vehicleID(0)
	, deleteStatus(_T("No Vehicles Deleted"))
{

}

deleteVehicleDlg::~deleteVehicleDlg()
{
}

void deleteVehicleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, vehicleID);
	DDX_Text(pDX, IDC_EDIT2, deleteStatus);
}


BEGIN_MESSAGE_MAP(deleteVehicleDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &deleteVehicleDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT2, &deleteVehicleDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// deleteVehicleDlg message handlers

void deleteVehicleDlg::OnBnClickedOk()
{
	UpdateData(true);

	bool found = false;
	int position;
	int i;

	for (i = 0; i < myVehicleArray.GetCount(); i++) // searching for the vehicle id
	{
		if ( (myVehicleArray[i]->getID()) == this->vehicleID)
		{
			found = true;
			position = i;
			break;
		}
	}
	
	// if flag is true -> delte , else dont delete
	if (found) // delete && print that deleted vehicle
	{
		if (myVehicleArray[position]->getNumberOfEmptySeats() != myVehicleArray[position]->getNumberOfSeats())
		{
			deleteStatus = "Unable to delete ordered Vehicle";
		}
		else
		{
			dummyVehicle = myVehicleArray.GetAt(position);
			delete dummyVehicle;
			myVehicleArray.RemoveAt(position);
			deleteStatus = "Vehicle Deleted";
		}
	}
	else // print to the Status box that the item was not found 
	{
		deleteStatus = "Vehicle not found";
	}

	found = false;
	UpdateData(false);
	vehicleDlg.UpdateData(false);
}


void deleteVehicleDlg::OnEnChangeEdit2()
{
	deleteStatus = "No Vehicle Deleted Yet";
	UpdateData(false);
	
}
