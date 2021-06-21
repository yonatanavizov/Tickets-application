// myTickets.cpp : implementation file
//

#include "pch.h"
#include "Ticket_Application.h"
#include "myTickets.h"
#include "afxdialogex.h"


// myTickets dialog

IMPLEMENT_DYNAMIC(myTickets, CDialogEx)

myTickets::myTickets(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TICKET_APPLICATION_DIALOG, pParent)
{

}

myTickets::~myTickets()
{
}

void myTickets::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(myTickets, CDialogEx)
END_MESSAGE_MAP()


// myTickets message handlers
