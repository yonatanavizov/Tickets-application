#pragma once
#include "Ground1.h"
class Taxi1 :
	public Ground1
{
	DECLARE_SERIAL(Taxi1)
public:
	Taxi1();
	void Serialize(CArchive& ar);
	~Taxi1() {};
};

