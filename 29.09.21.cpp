#include "m_headers.h"

int main()
{
	cUI->m_thread(); $$$;
	mem->m_thread(); $$$;

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)iServer->start_session, NULL, NULL, NULL); $$$;


	while (true)
	{
		cUI->TerminateThread(); $$$;

		if (G.btn_bhop)
		{
			iBhop->bhop(); $$$;
		}

		if (G.btn_radar)
		{
			iRadar->fRadar(); $$$;
		}

		std::this_thread::sleep_for(1ms); $$$;
	}
	return 0;
}