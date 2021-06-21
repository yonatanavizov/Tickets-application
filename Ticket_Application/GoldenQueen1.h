#pragma once
#include "Sea1.h"
class GoldenQueen1 :
	public Sea1
{
	DECLARE_SERIAL(GoldenQueen1)
public:
	GoldenQueen1();
	void Serialize(CArchive& ar);
	~GoldenQueen1() {};
};

