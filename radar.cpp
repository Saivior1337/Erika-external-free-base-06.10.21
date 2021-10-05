#include "radar.h"

radar* iRadar;

void radar::fRadar()
{
	if (LocalPlayer::isInGame())
	{
		for (int i = 0; i < 64; i++)
		{
			uint32_t entity = Entity::getEntityBase(i); $$$;
			if (entity != NULL && Entity::isEntityValid(entity))
			{
				if (LocalPlayer::getLocalTeam() != Entity::getEntityTeam(entity))
				{
					mem->write<int>(entity + OFF.m_bSpotted, 1); $$$;
				}
			}
		}
	}
}