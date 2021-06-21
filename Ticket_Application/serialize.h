//#pragma once
//#include <afx.h>
//#include "Vehicle.h"
//#include "Ticket_Application.h"
//
//class serialize :
//	public CObject
//{
//private:
//	Vehicle** saveLoadMe;
//public:
//	serialize();
//	void updatePointers(Vehicle** a) // inputs the address
//	{
//		for (int i = 0; i < 18; i++)
//		{
//			this->saveLoadMe[i] = a[i];
//			
//		}
//	};
//	void loadPointers(Vehicle** a)
//	{
//		for (int i = 0; i < 18; i++)
//		{
//			delete a[i];
//			a[i] = saveLoadMe[i];
//		}
//	};
//
//	void Serialize(CArchive& ar);
//};
//
//
