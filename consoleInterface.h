#pragma once
#include "m_headers.h"

class consoleInterface
{
public:
	void m_thread();
	void setupConsole();
	void ClearScreen();
	void TerminateThread();
};

extern consoleInterface * cUI;