#pragma once
#include <vector> 

#include "Player.h"
#include "Stone.h"
#include "GameMap.h"
#include "Gate.h"
#include "SFML/Graphics.hpp"
#include "../Define/Define.h"
#include "ResourceManager.h"
#include "Key.h"
#include <iostream>
using namespace std;

class GameManager
{
private:
	Player player;
	GameMap gameMap;
	vector<Stone> stoneEnemy;
	vector<UnableMovingRock> unRock;
	vector<AbleMovingRock> Rock;
	Gate gate;
	Key key;
	TimeBar timebar;
	int m_level = 0;
	static GameManager* s_Instance;

public:
	void Init(const char* textureName = "")
	{
		//get date from the level
		ResourceManager::getInstance()->loadLevel(stoneEnemy, unRock, Rock, player,gate, timebar, m_level);

		gameMap.Init(TEXTURE_BG);
		player.Init(ResourceManager::getInstance()->getPlayerImage(player.getColor()-1)); //set image depend on color of player
		for (int i = 0; i < stoneEnemy.size(); i++) {
			stoneEnemy[i].Init(ResourceManager::getInstance()->getStoneImage(stoneEnemy[i].getColor()-1)); //set image depend on color of stone
		}
		gate.Init(ResourceManager::getInstance()->getGateImage(0));
		timebar.Init(ResourceManager::getInstance()->getTimeBarImage(0));
		//init for other enemy
		/*
		Todo here
		*/
	}
	void Update(float dt, int num)
	{
		int flat = 1;
		gameMap.Update(dt, num);
		for (int i = 0; i < stoneEnemy.size(); i++) {
			if (stoneEnemy[i].getIsDeleted() == false)
			{
				int x = stoneEnemy[i].getM_mapx();
				int y = stoneEnemy[i].getM_mapy();
				printf("%d %d\t %d %d\n", x, y, player.getPosx(), player.getPosy());
				if ((x + 1 < MAX_MAP_COL && GameMap::m_map[x + 1][y] == PLAYER_ID && num == Keyboard::Left) || (x - 1 >= 0 && GameMap::m_map[x - 1][y] == PLAYER_ID && num == Keyboard::Right) ||
					(y + 1 < MAX_MAP_ROW && GameMap::m_map[x][y + 1] == PLAYER_ID && num == Keyboard::Up) || (y - 1 >= 0 && GameMap::m_map[x][y - 1] == PLAYER_ID && num == Keyboard::Down)) {
					if (player.getColor() == stoneEnemy[i].getColor())
					{
						if (stoneEnemy[i].Update(dt, num)) {
							player.Update(dt, num);
						}
					}
					flat = 0;
				}
			}

		}
		if (flat == 1)
			player.Update(dt, num);

		//Check collision
		int p_x = player.getM_mapx();
		int p_y = player.getM_mapy();
		int done = 0;
		switch (player.getDestroy()) {
			//destroy hang doc
		case 1:
		{
			int i_doneu = 0;
			int i_doned = 0;
			for (int i = 1; ; i++) {
				if ((p_y + i) >= 12 || GameMap::m_map[p_x][p_y + i] == 0) {
					i_doneu = 1;
				}
				if ((p_y - i) < 0 || GameMap::m_map[p_x][p_y - i] == 0) {
					i_doned = 1;
				}
				for (int j = 0; j < stoneEnemy.size(); j++) {
					if (stoneEnemy[j].getIsDeleted() == false)
					{
						int x = stoneEnemy[j].getM_mapx();
						int y = stoneEnemy[j].getM_mapy();
						if (((p_y + i) < 12 && x == p_x && y == p_y + i) || (p_y - i) >= 0 && x == p_x && y == p_y - i) {
							if (stoneEnemy[j].getIsKey()) {
								key.setPosx((x + 1) * 35 + 45);
								key.setPosy(y * 37 + 150);
								key.Init(ResourceManager::getInstance()->getKeyImage(0));
							}

							stoneEnemy[j].destroy();
							stoneEnemy[j].setIsDeleted(true);
						}
					}
				}
				if (i_doneu == 1 && i_doned ==1)
					break;
			}
			player.setDestroy(0);
		}
			break;
		case 2:
		{
			int i_donel = 0;
			int i_doner = 0;
			for (int i = 0; ; i++) {
				if ((p_x + i) >= 12 || GameMap::m_map[p_x+i][p_y] == 0) {
					i_donel = 1;
				}
				if ((p_x - i) < 0 || GameMap::m_map[p_x-i][p_y] == 0) {
					i_doner = 1;
				}
				for (int j = 0; j < stoneEnemy.size(); j++) {
					if (stoneEnemy[j].getIsDeleted() == false)
					{
						int x = stoneEnemy[j].getM_mapx();
						int y = stoneEnemy[j].getM_mapy();
						if (((p_x + i) < 12 && x == p_x + i && y == p_y) || (p_x - i) >= 0 && x == p_x - i && y == p_y) {
							if (stoneEnemy[j].getIsKey()) {
								key.setPosx((x + 1) * 35 + 45);
								key.setPosy(y * 37 + 150);
								key.Init(ResourceManager::getInstance()->getKeyImage(0));
							}
							stoneEnemy[j].destroy();
							stoneEnemy.erase(stoneEnemy.begin() + j);
							j--;
						}
					}
				}
				if (i_donel == 1 && i_doner == 1)
					break;
			}
			player.setDestroy(0);
		}
			break;
		default:
			break;
		}


		timebar.Update(dt,0);
		
	}
	void Render(sf::RenderWindow &window)
	{
		gameMap.Render(window);
		player.Render(window);
		for (int i = 0; i < stoneEnemy.size(); i++) {
			if (stoneEnemy[i].getIsDeleted() == false)
			{
				stoneEnemy[i].Render(window);
			}
		}
		if(player.getSetKey())
			gate.Render(window);
		else
			key.Render(window);
		timebar.Render(window);
	}
	void UpdateClickEvent(float dt, Vector2f mouse) {
		sf::FloatRect bounds = player.getSprite().getGlobalBounds();

		if (bounds.contains(mouse))
		{
			player.changeColor();
			player.UpdateColor(dt, ResourceManager::getInstance()->getPlayerImage(player.getColor()-1));
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
