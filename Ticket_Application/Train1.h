#pragma once
#include "Ground1.h"
class Train1 :
	public Ground1
{
	DECLARE_SERIAL(Train1)
public:
	Train1();
	void Serialize(CArchive& ar);
	~Train1() {};
};

