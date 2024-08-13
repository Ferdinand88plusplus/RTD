#include "BaseRTO.h"

void BaseRTO::sendRTOEvent(int sign, int info)
{
	
	RTOEvent* rtoev = new RTOEvent(sign, info);
	events.push_back(rtoev);
}

