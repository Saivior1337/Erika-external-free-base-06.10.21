#pragma once
#include "m_headers.h"

class server_session
{
public:
	static unsigned long __stdcall start_session(void*);
};

extern server_session* iServer;