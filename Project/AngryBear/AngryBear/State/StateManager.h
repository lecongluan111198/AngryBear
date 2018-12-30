#pragma once
#pragma once

#include "SFML/Graphics.hpp"
#include "../Define/Define.h"
#include "State.h"
class StateManager
{
private:
	static StateManager* s_Instance;

public:
	void Init()
	{
		
	}
	void Update(float dt)
	{
		
	}
	void Render(sf::RenderWindow &window)
	{
	}
	void SwitchState (State* state){}
	void Run() {};
	static StateManager* getInstance()
	{
		if (s_Instance == nullptr)
		{
			s_Instance = new StateManager();
		}
		return s_Instance;
	}

};

StateManager* StateManager::s_Instance = nullptr;
