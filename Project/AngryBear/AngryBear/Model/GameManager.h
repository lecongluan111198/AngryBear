#pragma once
#include <vector> 

#include "Player.h"
#include "Stone.h"
#include "Background.h"
#include "SFML/Graphics.hpp"
#include "../Define/Define.h"
#include <iostream>
using namespace std;

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
		//test
		Background::resizeMap();
		Background::m_map[player.getM_mapx()][player.getM_mapy()] = PLAYER_ID;

		//
		bacground.Init(TEXTURE_BG);
		player.Init(TEXTURE_BG);
		for (int i = 0; i < stoneEnemy.size(); i++) {
			stoneEnemy[i].Init(TEXTURE_PLAYER);
			//test
			stoneEnemy[i].setM_mapx(2);
			stoneEnemy[i].setM_mapy(2);
			//
		}
	}
	void Update(float dt,int num)
	{
		int flat = 1;
		bacground.Update(dt, num);
		for (int i = 0; i < stoneEnemy.size(); i++) {
			int x = stoneEnemy[i].getM_mapx();
			int y = stoneEnemy[i].getM_mapy();
			printf("%d %d\t %d %d\n", x, y, player.getM_mapx(), player.getM_mapy());
			//printf("%d %d %d %d\n", player.getPosx(), player.getPosy(), Background::m_map.size(), Background::m_map[0].size());
			if ((x + 1 < MAX_MAP_COL && Background::m_map[x + 1][y] == PLAYER_ID && num == Keyboard::Left) || (x - 1 >= 0 && Background::m_map[x - 1][y] == PLAYER_ID && num == Keyboard::Right) ||
				(y + 1 < MAX_MAP_ROW && Background::m_map[x][y + 1] == PLAYER_ID && num == Keyboard::Up) || (y - 1 >= 0 && Background::m_map[x][y - 1] == PLAYER_ID && num == Keyboard::Down)) {
				if (stoneEnemy[i].Update(dt, num)) {
					player.Update(dt, num);

				}
			}
			else {
				flat = 0;
			}
		}
		if(flat == 0)
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
