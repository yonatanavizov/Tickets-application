#pragma once
#include "Vehicle1.h"
class Sea1 :
	public Vehicle1
{
private:
	bool engineType; //Diesel 0 , Gas 1 
	void setType();

protected:
	Sea1();
	virtual void setDestinations();

public:
	virtual void Serialize(CArchive& archive)
	{
		CObject::Serialize(archive);
		Vehicle1::Serialize(archive);

		if (archive.IsStoring()) {
			archive << engineType;
		}
		else {
			archive >> engineType;
		}
	};

	~Sea1() {};
};

