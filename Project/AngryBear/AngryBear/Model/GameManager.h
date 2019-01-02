#pragma once
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "../Define/Define.h"
class GameManager
{
private:
	Player player;
	static GameManager* s_Instance;

public:
	void Init(const char* textureName = "")
	{
		player.Init(TEXTURE_BG);
	}
	void Update(float dt,int num)
	{
		player.Update(dt,num);
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
};

GameManager* GameManager::s_Instance = nullptr;
