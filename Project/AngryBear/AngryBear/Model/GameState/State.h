#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../Define/Define.h"

class State {

public:
	virtual void Init() = 0;
	virtual void HandleInit(int key) = 0; //process the event when clicking on special keyboard
	virtual void Update(float dt, int key) = 0;
	virtual void Render(sf::RenderWindow &window) = 0;
	virtual void Pause() {

	}
	virtual void Resume() {

	}
};