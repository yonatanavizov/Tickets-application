#pragma once
// Ticket_ApplicationDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Ticket_Application.h"
#include "Ticket_ApplicationDlg.h"
#include "afxdialogex.h"
#include "MyTickets2.h"
#include "ExistingVehicles.h"
#include "Taxi1.h"
#include "Boeing7371.h"
#include "GoldenQueen1.h"
#include "MAN_NL1.h"
#include "Train1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAfxIdcPicture();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CAboutDlg::OnAfxIdcPicture()
{
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_COMMAND(AFX_IDC_PICTURE, &CAboutDlg::OnAfxIdcPicture)
END_MESSAGE_MAP()


// CTicketApplicationDlg dialog



CTicketApplicationDlg::CTicketApplicationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TICKET_APPLICATION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
}





BEGIN_MESSAGE_MAP(CTicketApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK3, &CTicketApplicationDlg::OnBnClickedOk3)
	ON_BN_CLICKED(IDC_BUTTON2, &CTicketApplicationDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CTicketApplicationDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTicketApplicationDlg message handlers

BOOL CTicketApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTicketApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTicketApplicationDlg::OnPaint()
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
HCURSOR CTicketApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTicketApplicationDlg::OnBnClickedOk3()
{
	MyTickets2 dlg;
	dlg.DoModal();
}


BEGIN_EVENTSINK_MAP(CTicketApplicationDlg, CDialogEx)
	ON_EVENT(CTicketApplicationDlg, IDC_IMAGE2, DISPID_CLICK, CTicketApplicationDlg::ClickTickets, VTS_NONE)
	ON_EVENT(CTicketApplicationDlg, IDC_IMAGE3, DISPID_CLICK, CTicketApplicationDlg::ClickVehicles, VTS_NONE)
END_EVENTSINK_MAP()


void CTicketApplicationDlg::ClickTickets()
{
	ticketsDlg.DoModal();
}


void CTicketApplicationDlg::ClickVehicles()
{
	vehicleDlg.DoModal();
}


void CTicketApplicationDlg::OnBnClickedButton1() // save
{
	// Choice and open file ostream
	const TCHAR czFilter[] = _T("Vehicle Data files (*.data)|*.data|All Files (*.*)|*.*||");
	CFileDialog dlg(FALSE, _TEXT("vehicleData"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);


	if (dlg.DoModal() == IDOK)
	{
		CString fname = dlg.GetPathName();
		CFile fOut(fname, CFile::modeCreate | CFile::modeWrite);

		CArchive ar(&fOut, CArchive::store);

		int numberOfVeh = myVehicleArray.GetCount();
		ar << numberOfVeh;
		for (int i = 0; i < numberOfVeh; i++) {
			ar << myVehicleArray[i]->getVehicleType(); // save the type of this vehicle
			myVehicleArray[i]->Serialize(ar);
		}

		int numOfTick = myTicketsArray.GetCount();

		ar << numOfTick;
		for (int i = 0; i < numOfTick; i++) //save  tickets
		{
			myTicketsArray[i]->Serialize(ar);
		}

		ar.Close();
		fOut.Close();
	}
}	

void CTicketApplicationDlg::OnBnClickedButton2() // load
{

	// Choice and open file ostream
	const TCHAR czFilter[] = _T("Vehicle Data files (*.data)|*.data|All Files (*.*)|*.*||");
	CFileDialog dlg(TRUE, _TEXT("vehicleData"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);

	if (dlg.DoModal() == IDOK)
	{
		CString fname = dlg.GetPathName();
		CFile fOut(fname, CFile::modeRead);

		CArchive ar(&fOut, CArchive::load);

		// delete the current memory:
		while (myVehicleArray.GetCount() != 0)
		{
			dummyVehicle = myVehicleArray.GetAt(0);
			delete dummyVehicle;
			myVehicleArray.RemoveAt(0);
		}

		while (myTicketsArray.GetCount() != 0)
		{
			dummyTicket = myTicketsArray.GetAt(0);
			delete dummyTicket;
			myVehicleArray.RemoveAt(0);
		}

		//loading the new information
		int numberOfVeh;
		ar >> numberOfVeh;

		for (int i = 0; i < numberOfVeh; i++) // load vehicles
		{
			int vehicleType;
			ar >> vehicleType;
			switch (vehicleType) {
			case 1: // taxi
				dummyVehicle = new Taxi1();
				myVehicleArray.Add(dummyVehicle);
				break;
			case 2: // bus
				dummyVehicle = new MAN_NL1();
				myVehicleArray.Add(dummyVehicle);
				break;
			case 3: // train
				dummyVehicle = new Train1();
				myVehicleArray.Add(dummyVehicle);
				break;
			case 4: // boeing 737
				dummyVehicle = new Boeing7371();
				myVehicleArray.Add(dummyVehicle);
				break;
			case 5: // Golden Queen
				dummyVehicle = new GoldenQueen1();
				myVehicleArray.Add(dummyVehicle);
				break;
			}
			myVehicleArray[i]->Serialize(ar);

			dummyVehicle = NULL; // protect the inserted vehicle
		}

		int numOfTick;
		ar >> numOfTick;
		for (int i = 0; i < numOfTick; i++) //load tickets
		{
			dummyTicket = new Ticket1();
			myTicketsArray.Add(dummyTicket);
			myTicketsArray[i]->Serialize(ar);
		}

		ar.Close();
		fOut.Close();
	}

	for (int i = 0; i < myTicketsArray.GetCount(); i++) // update popinters to vehicles.
	{
		int vehicleID = myTicketsArray[i]->getVehicleID();
		for (int j = 0; j < myVehicleArray.GetCount(); j++)
		{
			if (myVehicleArray[j]->getID() == vehicleID)
			{
				myTicketsArray[i]->setVehiclePtr(myVehicleArray[j]);
				break;
			}
		}
	}

	for (int i = 0; i < myTicketsArray.GetCount(); i++) // update seats positions
	{
		myTicketsArray[i]->setSeatPosition(myTicketsArray[i]->getStartSeatPosition());
	}
}