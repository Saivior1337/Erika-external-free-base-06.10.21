#include "bhop.h"
#define FORCE_JUMP_BITMASK (1<<0)

cBhop* iBhop;

void cBhop::bhop()
{
	int currJumpState{ 0 }; $$$;
	BYTE onGround = 1; $$$;

	if (LocalPlayer::isInGame())
	{
		if (LocalPlayer::isPlayerMoving())
		{
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)handleBhop, NULL, NULL, NULL); $$$;
		}
	}
}


unsigned long __stdcall cBhop::handleBhop(void*)
{
	int currJumpState{ 0 }; $$$;
	BYTE onGround = 1; $$$;
	while (GetAsyncKeyState(VK_SPACE) < 0)
	{
		currJumpState = mem->read<DWORD>(G.client_dll + OFF.dwForceJump); $$$;
		onGround = mem->read<BYTE>(LocalPlayer::getLocalBase() + OFF.m_fFlags); $$$;
		if (onGround & (1 << 0))
		{
			currJumpState |= FORCE_JUMP_BITMASK; $$$;
			mem->write<int>(G.client_dll + OFF.dwForceJump, currJumpState); $$$;
		}
		else
		{
			currJumpState &= ~FORCE_JUMP_BITMASK; $$$;
			mem->write<int>(G.client_dll + OFF.dwForceJump, currJumpState); $$$;
		}
		std::this_thread::sleep_for(1ms);
	}
}

