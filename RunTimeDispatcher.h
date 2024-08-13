#pragma once

// RTO = RunTimeObject
// RTD = RunTimeDispatcher 

#include "global.h"
#include "RTOList.h"

// Core of everything in the game. Controls all the RTOs, window, resolution.
class RunTimeDispatcher
{

	sf::RenderWindow* window;
	sf::Vector2i res;

	std::vector<BaseRTO*> RTObjects;

	// Current RTO ID from RTOEv::Rto.
	int currRTO; 
	// Current RTO pointer.
	BaseRTO* rto;
	
	// Create all RTOs and add into RTObjects vector.
	void RTOInit();
	// Call Tick() in current RTO and check his events.
	void Tick();
	
public:
	RunTimeDispatcher();

	void Start();
};

