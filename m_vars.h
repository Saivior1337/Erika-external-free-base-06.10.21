#pragma once
#include "m_headers.h"

class m_Vars
{
public:
	DWORD processID;
	HANDLE hProcess, ConsoleHandle;
	uint32_t client_dll, engine_dll, vstdlib_dll, client_dll_size, engine_dll_size, vstdlib_dll_size;
	bool btn_bhop, btn_radar;
};

class m_Offsets
{
public:
	DWORD dwLocalPlayer = 0xDA244C;
	DWORD m_iTeamNum = 0xF4;
	DWORD dwEntityList = 0x4DBC5B4;
	DWORD dwForceJump = 0x52663C4;
	DWORD m_fFlags = 0x104;
	DWORD m_bSpotted = 0x93D;
	DWORD m_bSpottedByMask = 0x980;
	DWORD m_vecViewOffset = 0x108;
	DWORD m_iHealth = 0x100;
	DWORD dwClientState = 0x588FEC;
	DWORD m_vecVelocity = 0x114;
	DWORD dwClientState_PlayerInfo = 0x52C0;
	DWORD m_bGunGameImmunity = 0x9990;
	DWORD m_bDormant = 0xED;

};

extern m_Vars G;
extern m_Offsets OFF;