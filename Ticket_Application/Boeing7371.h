#pragma once
#include "Aerial1.h"
class Boeing7371 :
	public Aerial1
{
	DECLARE_SERIAL(Boeing7371)
public:
	Boeing7371();
	void Serialize(CArchive& ar);
	~Boeing7371() {};
};

