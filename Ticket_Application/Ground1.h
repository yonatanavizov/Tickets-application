#pragma once
#include "Vehicle1.h"
class Ground1 :
	public Vehicle1
{
private:
	int numberOfWheels;
	void setType();

protected:
	Ground1();
	virtual void setDestinations();
	void setNumberOfWheels(int _number) { this->numberOfWheels = _number; };

public:
	virtual void Serialize(CArchive& archive)
	{
		CObject::Serialize(archive);
		Vehicle1::Serialize(archive);

		if (archive.IsStoring()) {
			archive << numberOfWheels;
		}
		else {
			archive >> numberOfWheels;
		}
	};

	~Ground1() {};
};

