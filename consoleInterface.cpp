#include "consoleInterface.h"

consoleInterface * cUI;

void consoleInterface::setupConsole()
{
	cUI->ClearScreen(); $$$;
	SetConsoleTitle(XOR("Erika base by Saivior1337  // 06.10.2021")); $$$;
	HWND console = GetConsoleWindow(); $$$;
	RECT ConsoleRect; $$$;
	GetWindowRect(console, &ConsoleRect); $$$;
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 950, 400, TRUE); $$$;
}

void consoleInterface::ClearScreen()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi; $$$;
	DWORD                      count; $$$;
	DWORD                      cellCount; $$$;
	COORD                      homeCoords = { 0, 0 }; $$$;

	if (G.ConsoleHandle == INVALID_HANDLE_VALUE) return; $$$;

	if (!GetConsoleScreenBufferInfo(G.ConsoleHandle, &csbi)) return; $$$;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y; $$$;

	if (!FillConsoleOutputCharacter(G.ConsoleHandle, (TCHAR)' ', cellCount, homeCoords, &count)) return; $$$;

	if (!FillConsoleOutputAttribute(G.ConsoleHandle, csbi.wAttributes, cellCount, homeCoords, &count)) return; $$$;

	SetConsoleCursorPosition(G.ConsoleHandle, homeCoords); $$$;
}

void consoleInterface::TerminateThread()
{
	if (GetAsyncKeyState(VK_END) & 1)
	{
		exit(0); $$$;
	}
}

void consoleInterface::m_thread()
{
	G.ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); $$$;
	setupConsole(); $$$;
}