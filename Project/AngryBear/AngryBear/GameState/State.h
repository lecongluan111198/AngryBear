#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Define/Define.h"
using namespace std;
class State {

public:
	virtual void Init() = 0;
	virtual void HandleInit(int key) = 0; //process the event when clicking on special keyboard
	virtual void Update(float dt, int key) = 0;
	virtual void Render(sf::RenderWindow &window) = 0;
	virtual bool isComplete() = 0;
	virtual void UpdateClickEvent(float dt, Vector2f mouse) { }
	virtual void Pause() {

	}
	virtual void Resume() {

	}

	
};