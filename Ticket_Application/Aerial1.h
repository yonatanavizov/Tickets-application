#pragma once
#include "Vehicle1.h"
class Aerial1 :
	public Vehicle1
{
private:
	bool engineJetPropelor; //Jet 0 , Propelor 1
	void setType();

protected:
	Aerial1();
	virtual void setDestinations();

public:
	bool getEngineType() { return this->engineJetPropelor; }

	virtual void Serialize(CArchive& archive)
	{
		CObject::Serialize(archive);
		Vehicle1::Serialize(archive);

		if (archive.IsStoring()) {
			archive << engineJetPropelor;
		}
		else {
			archive >> engineJetPropelor;
		}
	};

	~Aerial1() {};
};

