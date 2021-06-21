
// Ticket_Application.h : main header file for the PROJECT_NAME application
//

#pragma once
//#include <boost/archive/text_oarchive.hpp>

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "Vehicle1.h"
#include "ExistingVehicles.h"
#include "MyTickets2.h"
#include "Ticket1.h"

const int MAX_NUMBER_OF_VEHICLES = 18;
const int MAX_NUMBER_OF_TICKETS = 9;



// CTicketApplicationApp:
// See Ticket_Application.cpp for the implementation of this class
//

class CTicketApplicationApp : public CWinApp
{
public:
	CTicketApplicationApp();

// Overrides
public:
	virtual BOOL InitInstance();


// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Vehicle1* dummyVehicle;
extern Ticket1* dummyTicket;
extern CTicketApplicationApp theApp;
extern CTypedPtrArray<CObArray, Vehicle1*> myVehicleArray; // declaring the global vehicle1 array
extern CTypedPtrArray<CObArray, Ticket1*> myTicketsArray;
extern ExistingVehicles vehicleDlg;
extern MyTickets2 ticketsDlg;