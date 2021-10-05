#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <chrono>
#include <thread>
#include <string>
#include <tchar.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <urlmon.h>
#include <fstream>
#include "Lmcons.h"
#include "ProcMem.h"
#include "m_vars.h"
#include "consoleInterface.h"
#include "xor.h"
#include "bhop.h"
#include "Entity.h"
#include "server_thread.h"
#include "radar.h"



#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

using namespace std::chrono_literals;

#define $$$ __asm      \
{                      \
	__asm _emit 0xEB      \
	__asm _emit 0x06      \
	__asm _emit 0xAA\
	__asm _emit 0xEE\
	__asm _emit 0xFF\
	__asm _emit 0xBB\
	__asm _emit 0xDD\
	__asm _emit 0xCC\
} 
