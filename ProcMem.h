#pragma once
#include "m_headers.h"

class Memory
{
public:
	DWORD hGetWindowProcessId();
	uint32_t getModule(const char* moduleName);
	void attachProcess();
	void m_thread();

	template<class T>
	BOOL write(uint32_t address, T buffer)
	{
		return WriteProcessMemory(G.hProcess, (LPVOID)address, &buffer, sizeof(T), NULL);
	}

	template <class dataType>
	dataType read(uint32_t addressToRead)
	{
		dataType rpmBuffer;
		ReadProcessMemory(G.hProcess, (PVOID)addressToRead, &rpmBuffer, sizeof(dataType), 0);
		return rpmBuffer;
	}
};

extern Memory * mem;