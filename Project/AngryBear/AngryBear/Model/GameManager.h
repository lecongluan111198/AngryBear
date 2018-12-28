#pragma once
#include "Player.h"
#include "SFML/Graphics.hpp"
class GameManager
{
private:
	Player player;
	//Enemy enemy[ENEMY_COUNT];

public:
	void Init(const char* textureName = "", int x = 0, int y = 0)
	{
		player.Init(textureName, 300, 200);
	}
	void Update(float dt)
	{
		player.Update(dt);
	}
	void Render(sf::RenderWindow &window)
	{
		
		player.Render(window);

	}

	static GameManager* getInstance()
	{
		if (s_Instance == nullptr)
		{
			s_Instance = new GameManager();
		}
		return s_Instance;
	}
private:
	// =================================================
	static GameManager* s_Instance;

	// =================================================


};

GameManager* GameManager::s_Instance = nullptr;
