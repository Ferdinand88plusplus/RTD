
#include "RunTimeDispatcher.h"


void RunTimeDispatcher::RTOInit()
{
// 	Create here your RTOs and add to RTObjects, for example:
//	yourRTO* yRTO = new yourRTO;
//	RTObjects.push_back(yourRTO);
	
	currRTO = 0; // and put here index of your starting RTO.

	rto = RTObjects[currRTO];
}

void RunTimeDispatcher::Tick()
{
	 
	if (!rto->inited) { 
		rto->window = window;
		rto->res = res;
		rto->Init(); 
		
		rto->inited = 1;
	}

	rto->Tick();

	bool terminate = 0;

	while(rto->events.size()){
		RTOEvent* rtoev = rto->events[0];

		switch (rtoev->sign)
		{
		default:
			rtd::critErr("Unknown event sign from RTO, event: " + std::to_string(rtoev->sign) + ' ' + std::to_string(rtoev->info));
			break;
		case RTOEv::Sign::CLOSE_WINDOW:
			window->close();
			rtd::log("Window closing after RTO event.");
			terminate = 1;
			break;
		case RTOEv::Sign::CHANGE_RTO:
			currRTO = rtoev->info;
			rto->DeInit();
			rto->inited = 0;
			rto = RTObjects[currRTO];
			terminate = 1;
			break;
		case RTOEv::Sign::SET_FPS_LIMIT:
			window->setFramerateLimit(rtoev->info);
			break;
		}

		if (terminate) break;

		delete rtoev;
		rto->events.erase(rto->events.begin(), rto->events.begin() + 1);
	}

	
}



RunTimeDispatcher::RunTimeDispatcher()
{
	res.x = 800;
	res.y = 600;

	window = new sf::RenderWindow;
	window->create(sf::VideoMode(res.x, res.y), "Testo");
}

void RunTimeDispatcher::Start()
{
	RTOInit();
	while (window->isOpen()) {
		sf::Event sfev;
		while (window->pollEvent(sfev)) {
			if (sfev.type == sfev.Closed) window->close();
		}

		window->clear();
		Tick();
		window->display();
	}

	saveLog();
}
