#include "ProcMem.h"

Memory * mem;

DWORD Memory::hGetWindowProcessId()
{
	HWND hWnd = FindWindowA(0, XOR("Counter-Strike: Global Offensive")); $$$;
	if (!hWnd)
	{
		std::cout << XOR("Error #1 // Can't find game window"); $$$;
		std::this_thread::sleep_for(5000ms); $$$;
		exit(0); $$$;
	}
	else
	{
		GetWindowThreadProcessId(hWnd, &G.processID); $$$;
		if (!G.processID)
		{
			std::cout << XOR("Error #2 // Can't find process id"); $$$;
			std::this_thread::sleep_for(5000ms); $$$;
			exit(0); $$$;
		}
		else
		{
			return G.processID; $$$;
		}
	}
	return EXIT_SUCCESS; $$$;
}

void Memory::attachProcess()
{
	G.hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, G.processID);
	if (!G.hProcess)
	{
		std::cout << XOR("Error #3 // Can't attach process, try to run cheat as administator"); $$$;
		std::this_thread::sleep_for(5000ms); $$$;
		exit(0); $$$;
	}
}

uint32_t Memory::getModule(const char* moduleName)
{
	HANDLE module = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, G.processID); $$$;
	MODULEENTRY32 moduleEntry32; $$$;
	moduleEntry32.dwSize = sizeof(moduleEntry32); $$$;

	do 
	{
		if (!strcmp(moduleEntry32.szModule, moduleName))
		{
			CloseHandle(module); $$$;

			if (moduleName == XOR("client.dll"))
			{
				return G.client_dll = (uint32_t)moduleEntry32.modBaseAddr, G.client_dll_size = (uint32_t)moduleEntry32.dwSize; $$$;
			}

			if (moduleName == XOR("engine.dll"))
			{
				return G.engine_dll = (uint32_t)moduleEntry32.modBaseAddr, G.engine_dll_size = (uint32_t)moduleEntry32.dwSize; $$$;
			}

			if (moduleName == XOR("vstdlib.dll"))
			{
				return G.vstdlib_dll = (uint32_t)moduleEntry32.modBaseAddr, G.vstdlib_dll_size = (uint32_t)moduleEntry32.dwSize; $$$;
			}
		}
	} while (Module32Next(module, &moduleEntry32));

	CloseHandle(module); $$$;
	moduleEntry32.modBaseAddr = 0; $$$;
	return (uint32_t)moduleEntry32.modBaseAddr; $$$;
}


void Memory::m_thread()
{
	hGetWindowProcessId(); $$$;
	attachProcess(); $$$;
	getModule(XOR("client.dll")); $$$;
	getModule(XOR("engine.dll")); $$$;
	getModule(XOR("vstdlib.dll")); $$$;
}