#pragma once
#include <vector> 

#include "Player.h"
#include "Stone.h"
#include "Background.h"
#include "SFML/Graphics.hpp"
#include "../Define/Define.h"
#include "ResourceManager.h"
#include <iostream>
using namespace std;

class GameManager
{
private:
	Player player;
	Background bacground;
	vector<Stone> stoneEnemy;
	vector<UnableMovingRock> unRock;
	vector<AbleMovingRock> Rock;

	int m_level = 0;
	static GameManager* s_Instance;

public:
	void Init(const char* textureName = "")
	{
		//get date from the level
		ResourceManager::getInstance()->loadLevel(stoneEnemy, unRock, Rock, player, m_level);

		bacground.Init(TEXTURE_BG);
		player.Init(ResourceManager::getInstance()->getPlayerImage(player.getColor())); //set image depend on color of player
		for (int i = 0; i < stoneEnemy.size(); i++) {
			stoneEnemy[i].Init(ResourceManager::getInstance()->getStoneImage(stoneEnemy[i].getColor())); //set image depend on color of stone
		}

		//init for other enemy
		/*
		Todo here
		*/
	}
	void Update(float dt,int num)
	{
		int flat = 1;
		bacground.Update(dt, num);
		for (int i = 0; i < stoneEnemy.size(); i++) {
			int x = stoneEnemy[i].getM_mapx();
			int y = stoneEnemy[i].getM_mapy();
			printf("%d %d\t %d %d\n", x, y, player.getPosx(), player.getPosy());
			if ((x + 1 < MAX_MAP_COL && Background::m_map[x + 1][y] == PLAYER_ID && num == Keyboard::Left) || (x - 1 >= 0 && Background::m_map[x - 1][y] == PLAYER_ID && num == Keyboard::Right) ||
				(y + 1 < MAX_MAP_ROW && Background::m_map[x][y + 1] == PLAYER_ID && num == Keyboard::Up) || (y - 1 >= 0 && Background::m_map[x][y - 1] == PLAYER_ID && num == Keyboard::Down)) {
				if (stoneEnemy[i].Update(dt, num)) {
					player.Update(dt, num);
					
				}
				flat = 0;
			}
			
		}
		if(flat == 1)
			player.Update(dt, num);
		
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
