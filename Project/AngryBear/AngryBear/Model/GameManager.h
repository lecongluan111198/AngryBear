#pragma once
#include "Player.h"
#include "Background.h"
#include "SFML/Graphics.hpp"
#include "../Define/Define.h"
class GameManager
{
private:
	Player player;
	Background bacground;
	static GameManager* s_Instance;

public:
	void Init(const char* textureName = "")
	{
		bacground.Init(TEXTURE_BG);
		player.Init(TEXTURE_BG);
	}
	void Update(float dt,int num)
	{
		player.Update(dt,num);
	}
	void Render(sf::RenderWindow &window)
	{
		bacground.Render(window);
		player.Render(window);

	}
	void UpdateColor(float dt, Vector2f mouse) {
		sf::FloatRect bounds = player.getSpite().getGlobalBounds();

		
		if (bounds.contains(mouse))
		{
			player.UpdateColor(dt);
		}
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
