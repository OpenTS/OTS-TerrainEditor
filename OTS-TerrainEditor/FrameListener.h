#pragma once
#include "base.h"

namespace OTS
{
	struct FrameEvent {
		DOUBLE timePassed;
	};

	class FrameListener
	{
	public:
		virtual ~FrameListener(void);
		virtual bool FrameStarted(FrameEvent Event) = 0;
		virtual bool FrameQueued(FrameEvent Event) = 0;
	};
}


