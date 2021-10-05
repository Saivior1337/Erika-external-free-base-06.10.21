#include "Entity.h"

uint32_t LocalPlayer::getLocalBase()
{
	return mem->read<uint32_t>(G.client_dll + OFF.dwLocalPlayer); $$$;
}

uint32_t LocalPlayer::getClientState()
{
	return mem->read<uint32_t>(G.engine_dll + OFF.dwClientState); $$$;
}

int LocalPlayer::getLocalFlags()
{
	return mem->read<int>(LocalPlayer::getLocalBase() + OFF.m_fFlags); $$$;
}

int LocalPlayer::getLocalTeam()
{
	return mem->read<int>(LocalPlayer::getLocalBase() + OFF.m_iTeamNum); $$$;
}

int LocalPlayer::getLocalHealth()
{
	return mem->read<int>(LocalPlayer::getLocalBase() + OFF.m_iHealth); $$$;
}


bool LocalPlayer::isInGame()
{
	int getGameState = mem->read<int>(LocalPlayer::getClientState() + OFF.m_vecViewOffset); $$$;
	if (getGameState == 6)
		return true;
	else
		return false;
}

bool LocalPlayer::isPlayerMoving()
{
	Vec3 Velocity = mem->read<Vec3>(LocalPlayer::getLocalBase() + OFF.m_vecVelocity); $$$;
	float isMoving = Velocity.x + Velocity.y + Velocity.z; $$$;
	if (isMoving != 0.0f)
		return true;
	else
		return false;
}

uint32_t Entity::getEntityBase(int index)
{
	return mem->read<uint32_t>(G.client_dll + OFF.dwEntityList + (index * 0x10)); $$$;
}

int Entity::getEntityTeam(uint32_t entity)
{
	return mem->read<int>(entity + OFF.m_iTeamNum); $$$;
}

int Entity::getEntityHealth(uint32_t entity)
{
	return mem->read<int>(entity + OFF.m_iHealth);
}

int Entity::getClassID(uint32_t entity)
{
	DWORD dwClientNetworkable = mem->read<DWORD>(entity + 0x8);
	DWORD dwGetClientClassFn = mem->read<DWORD>(dwClientNetworkable + 2 * 0x4);
	DWORD dwEntityClientClass = mem->read<DWORD>(dwGetClientClassFn + 1);
	return mem->read<int>(dwEntityClientClass + 20);
}


bool Entity::isEntityHasImmunity(uint32_t entity)
{
	return mem->read<bool>(entity + OFF.m_bGunGameImmunity); $$$;
}

bool Entity::isEntitySpotted(uint32_t entity)
{
	return mem->read<bool>(entity + OFF.m_bSpottedByMask); $$$;
}

bool Entity::isEntityVisible(uint32_t entity)
{
	return mem->read<bool>(entity + OFF.m_bSpotted); $$$;
}

bool Entity::isEntityAlive(uint32_t entity)
{
	if (Entity::getEntityHealth(entity) > 0 && Entity::getEntityHealth(entity) <= 100)
		return true;
	return false;
}

bool Entity::isEntityValid(uint32_t entity)
{
	bool dormant = mem->read<bool>(entity + OFF.m_bDormant); $$$;
	if ((Entity::isEntityAlive(entity) && Entity::getEntityTeam(entity) != 0) && !dormant)
		return true;
	return false;
}

player_info_t Entity::getEntityInformation(int index)
{
	uintptr_t UserInfoTable = mem->read<uintptr_t>(LocalPlayer::getClientState() + OFF.dwClientState_PlayerInfo); $$$;
	uintptr_t x = mem->read<uintptr_t>(mem->read<uintptr_t>(UserInfoTable + 0x40) + 0xC); $$$;
	return mem->read<player_info_t>(mem->read<uintptr_t>(x + 0x28 + 0x34 * index)); $$$;
}