#pragma once
#include <vector> 

#include "Player.h"
#include "Stone.h"
#include "Background.h"
#include "SFML/Graphics.hpp"
#include "../Define/Define.h"

class GameManager
{
private:
	Player player;
	Background bacground;
	std::vector<Stone> stoneEnemy;
	static GameManager* s_Instance;
	GameManager() {
		stoneEnemy.resize(1);
	}
public:
	void Init(const char* textureName = "")
	{
		bacground.Init(TEXTURE_BG);
		player.Init(TEXTURE_BG);
		for (int i = 0; i < stoneEnemy.size(); i++) {
			stoneEnemy[i].Init(TEXTURE_PLAYER);
		}
	}
	void Update(float dt,int num)
	{
		player.Update(dt,num);
		bacground.Update(dt, num);
		for (int i = 0; i < stoneEnemy.size(); i++) {
			if (player.getPosx() == stoneEnemy[i].getPosx() && player.getPosy() == stoneEnemy[i].getPosy())
			{
				stoneEnemy[i].Update(dt, num);
			}
		}
	}
	void Render(sf::RenderWindow &window)
	{
		bacground.Render(window);
		player.Render(window);
		for (int i = 0; i < stoneEnemy.size(); i++) {
			stoneEnemy[i].Render(window);
		}
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
