#pragma once
#include "m_headers.h"

class cBhop
{
public:
	void bhop();
	static unsigned long __stdcall handleBhop(void*);
};

extern cBhop * iBhop;