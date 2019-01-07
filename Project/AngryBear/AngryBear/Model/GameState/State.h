#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class State {

public:
	virtual void Init() = 0;
	virtual void HandleInit(int key) = 0; //process the event when clicking on special keyboard
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	virtual void Pause();
	virtual void Resume();
};