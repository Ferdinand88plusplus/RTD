#pragma once

#include "global.h"

#include "RTOEvent.h"
#include "StatusLog.h"

/*
Basic-abstract game object.
Has access to sfml window, window resolution.
Can send events to RTD.
After you'll create a class based on this,
dont forgot to add him into RTD targets 
in RunTimeDispatcher::RTOInit(), and in 
RTOEv::Rto enum.
*/
class BaseRTO
{
public:

	sf::RenderWindow* window;
	sf::Vector2i res;

	bool inited = 0;

	std::vector<RTOEvent*> events;

	// Calls when this RTO is gets setted.
	virtual void Init() = 0;
	// Calls every frame
	virtual void Tick() = 0;
	// Calls after new RTO setted.
	virtual void DeInit() = 0;

	// Send event to global Runtime Dispatcher.
	void sendRTOEvent(int sign, int info);
};
