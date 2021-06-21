#pragma once
#include "Ground1.h"
class MAN_NL1 :
	public Ground1
{
	DECLARE_SERIAL(MAN_NL1)
public:
	MAN_NL1();
	void Serialize(CArchive& ar);
	~MAN_NL1() {};
};

