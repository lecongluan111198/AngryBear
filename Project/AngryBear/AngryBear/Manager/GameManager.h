#pragma once
#include <vector> 
#include <iostream>
#include "../Define/Define.h"
#include "../Model/Player.h"
#include "../Model/Stone.h"
#include "../Model/GameMap.h"
#include "../Model/Gate.h"
#include "../Model/Explode.h"
#include "../Model/Key.h"
#include "../Model/UnableMovingRock.h"
#include "../Model/AbleMovingRock.h"
#include "../Model/TimeBar.h"
#include "../Model/Boom.h"
#include "SFML/Graphics.hpp"
#include "ResourceManager.h"


using namespace std;

class GameManager
{
private:
	//sf::Clock clock;
	int Timer;
	Player player;
	GameMap gameMap;
	vector<Stone> stoneEnemy;
	vector<UnableMovingRock> unRock;
	vector<AbleMovingRock> Rock;
	vector< Explode> explode;
	vector<Boom> boom;
	Gate gate;
	Key key;
	Explode ex;
	TimeBar timebar;
	static GameManager* s_Instance;
	int isComplete = UNCOMPLETE;
	bool showingKey;
	int m_level = 0;
public:
	
	void Init()
	{
		stoneEnemy.clear();
		unRock.clear();
		Rock.clear();
		explode.clear();
		isComplete = UNCOMPLETE;
		showingKey= false;

		//set start time
		//clock.restart();
		//Timer = 0;

		//get date from the level
		ResourceManager::getInstance()->loadLevel(stoneEnemy, unRock, Rock, player, gate, timebar, boom, m_level);

		gameMap.Init(TEXTURE_BG);
		player.Init(ResourceManager::getInstance()->getPlayerImage(player.getColor()-1)); //set image depend on color of player
		for (int i = 0; i < stoneEnemy.size(); i++) {
			stoneEnemy[i].Init(ResourceManager::getInstance()->getStoneImage(stoneEnemy[i].getColor()-1)); //set image depend on color of stone
		}
		for (int i = 0; i < unRock.size(); i++) {
			unRock[i].Init(ResourceManager::getInstance()->getUnRockImage(0));
		}
		for (int i = 0; i < Rock.size(); i++) {
			Rock[i].Init(ResourceManager::getInstance()->getRockImage(0));
		}
		for (int i = 0; i < boom.size(); i++) {
			boom[i].Init(ResourceManager::getInstance()->getBoomImage(0));
		}
		gate.Init(ResourceManager::getInstance()->getGateImage(0));
		timebar.Init(ResourceManager::getInstance()->getTimeBarImage(0));
	}
	void Update(float dt, int num)
	{
		if (num == Keyboard::Space)
		{
			player.changeColor();
			player.UpdateColor(dt, ResourceManager::getInstance()->getPlayerImage(player.getColor() - 1));
		}

		int flat = 1;
		gameMap.Update(dt, num);
		for (int i = 0; i < stoneEnemy.size(); i++) {
			if (stoneEnemy[i].getIsDeleted() == false)
			{
				int x = stoneEnemy[i].getM_mapx();
				int y = stoneEnemy[i].getM_mapy();
				
				if ((x + 1 < MAX_MAP_COL && GameMap::m_map[x + 1][y] == PLAYER_ID && num == Keyboard::Left) || (x - 1 >= 0 && GameMap::m_map[x - 1][y] == PLAYER_ID && num == Keyboard::Right) ||
					(y + 1 < MAX_MAP_ROW && GameMap::m_map[x][y + 1] == PLAYER_ID && num == Keyboard::Up) || (y - 1 >= 0 && GameMap::m_map[x][y - 1] == PLAYER_ID && num == Keyboard::Down)) {
					if (player.getColor() == stoneEnemy[i].getColor())
					{
						if (stoneEnemy[i].Update(dt, num)) {
							if (stoneEnemy[i].getIsDeleted()) {
								
								for (int j = 0; j < boom.size(); j++) {
									if (boom[j].getPosx() == stoneEnemy[i].getPosx() && boom[j].getPosy() == stoneEnemy[i].getPosy())
									{
										boom[j].setIsExplode(true);
										ex.setPosx(boom[j].getPosx());
										ex.setPosy(boom[j].getPosy());
										ex.Init(ResourceManager::getInstance()->getExplodeImage(0));
										explode.push_back(ex);
									}
								}
							}
								player.Update(dt, num);
						}
					}
					flat = 0;
				}
			}

		}

		for (int i = 0; i < unRock.size(); i++) {
			if (unRock[i].getIsDeleted() == false)
			{
				int x = unRock[i].getM_mapx();
				int y = unRock[i].getM_mapy();

				if ((x + 1 < MAX_MAP_COL && GameMap::m_map[x + 1][y] == PLAYER_ID && num == Keyboard::Left) || (x - 1 >= 0 && GameMap::m_map[x - 1][y] == PLAYER_ID && num == Keyboard::Right) ||
					(y + 1 < MAX_MAP_ROW && GameMap::m_map[x][y + 1] == PLAYER_ID && num == Keyboard::Up) || (y - 1 >= 0 && GameMap::m_map[x][y - 1] == PLAYER_ID && num == Keyboard::Down)) {

					flat = 0;
				}
			}
		}

		for (int i = 0; i < Rock.size(); i++) {
			if (Rock[i].getIsDeleted() == false)
			{
				int x = Rock[i].getM_mapx();
				int y = Rock[i].getM_mapy();

				if ((x + 1 < MAX_MAP_COL && GameMap::m_map[x + 1][y] == PLAYER_ID && num == Keyboard::Left) || (x - 1 >= 0 && GameMap::m_map[x - 1][y] == PLAYER_ID && num == Keyboard::Right) ||
					(y + 1 < MAX_MAP_ROW && GameMap::m_map[x][y + 1] == PLAYER_ID && num == Keyboard::Up) || (y - 1 >= 0 && GameMap::m_map[x][y - 1] == PLAYER_ID && num == Keyboard::Down)) {
					if (Rock[i].Update(dt, num)) {
						if (Rock[i].getIsDeleted()) {
							
							for (int j = 0; j < boom.size(); j++) {
								if (boom[j].getPosx() == Rock[i].getPosx() && Rock[j].getPosy() == Rock[i].getPosy())
								{
									boom[j].setIsExplode(true);
									ex.setPosx(boom[j].getPosx());
									ex.setPosy(boom[j].getPosy());
									ex.Init(ResourceManager::getInstance()->getExplodeImage(0));
									explode.push_back(ex);
								}
							}
						}
						player.Update(dt, num);
					}
					flat = 0;
				}
			}
		}

		if (flat == 1)
			player.Update(dt, num);
		if (player.getIsDead()) {
			for (int i = 0; i < boom.size(); i++) {
				if (boom[i].getPosx() == player.getPosx() && boom[i].getPosy() == player.getPosy())
				{
					boom[i].setIsExplode(true);
					ex.setPosx(boom[i].getPosx());
					ex.setPosy(boom[i].getPosy());
					ex.Init(ResourceManager::getInstance()->getExplodeImage(0));
					explode.push_back(ex);
				}
			}
		}
		//Check collision
		int p_x = player.getM_mapx();
		int p_y = player.getM_mapy();
		int done = 0;
		
		switch (player.getDestroy()) {
		case 1: //destroy hang doc
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
								showingKey= true;
							}
							
							//destroy enemy
							stoneEnemy[j].destroy();
							stoneEnemy[j].setIsDeleted(true);

							//initializing animation killing enemy 
							ex.setPosx((x + 1) * 35 + 45);
							ex.setPosy(y * 37 + 150);
							ex.Init(ResourceManager::getInstance()->getExplodeImage(0));
							explode.push_back(ex);
						}
					}
				}
				if (i_doneu == 1 && i_doned ==1)
					break;
			}
			player.setDestroy(0);
		}
			break;
		case 2: //destroy hang ngang
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
								showingKey= true;
							}
							//destroy enemy
							stoneEnemy[j].destroy();
							stoneEnemy[j].setIsDeleted(true);

							//initializing animation killing enemy 
							ex.setPosx((x + 1) * 35 + 45);
							ex.setPosy(y * 37 + 150);
							ex.Init(ResourceManager::getInstance()->getExplodeImage(0));
							explode.push_back(ex);

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

		for (int i = 0; i < explode.size(); i++) {
			if (!explode[i].isExpired())
			{
				explode[i].Update(dt, 0);
			}
		}

		timebar.Update(dt,0);
		if (dt - timebar.getStartTime() > MAX_TIME)
		{
			isComplete = GAMEOVER;
		}
		if (player.getSetKey())
		{
			explodeAll();
			//isComplete = WIN;
		}
	}
	void Render(sf::RenderWindow &window)
	{
		bool flag = false;
		gameMap.Render(window);
		if(player.getIsDead() == false)
			player.Render(window);
		int j = 0;
		for (int i = 0; i < explode.size(); i++) {
			if (!explode[i].isExpired())
			{
				explode[i].Render(window);
				flag = true;
			}
		}
		for (int i = 0; i < boom.size(); i++) {
			if (boom[i].getIsExplode()==false)
			{
				boom[i].Render(window);
			}
		}
		for (int i = 0; i < stoneEnemy.size(); i++) {
			if (stoneEnemy[i].getIsDeleted() == false)
			{
				stoneEnemy[i].Render(window);
			}
		}
		for (int i = 0; i < unRock.size(); i++) {
			if (unRock[i].getIsDeleted() == false)
			{
				unRock[i].Render(window);
			}
		}

		for (int i = 0; i < Rock.size(); i++) {
			if (Rock[i].getIsDeleted() == false)
			{
				Rock[i].Render(window);
			}
		}

		
		if (!flag) {
			explode.clear();
		}
		if (player.getSetKey() && !flag)
		{
			isComplete = WIN;
			gate.Render(window);
		}
		else if(showingKey)
		{
			key.Render(window);
		}
		timebar.Render(window);
		
	}
	void UpdateClickEvent(float dt, Vector2f mouse) {
		sf::FloatRect bounds = player.getSprite().getGlobalBounds();

		
		if (bounds.contains(mouse))
		{
			player.changeColor();
			player.UpdateColor(dt, ResourceManager::getInstance()->getPlayerImage(player.getColor() - 1));
		}
	}
	
	int getIsComplete() {
		return isComplete;
	}
	static GameManager* getInstance()
	{
		if (s_Instance == nullptr)
		{
			s_Instance = new GameManager();
		}
		return s_Instance;
	}

	int getLevel() {
		return m_level;
	}
	void setLevel(int levelID) {
		m_level = levelID;
	}
	void nextLevel() {
		if (m_level + 1 < ResourceManager::getInstance()->getMaxLevel())
			m_level++;
		else
			m_level = 0;
	}

	void explodeAll() {
		int x;
		int y;
		for (int i = 0; i < stoneEnemy.size(); i++) {
			if (stoneEnemy[i].getIsDeleted() == false)
			{
				x = stoneEnemy[i].getM_mapx();
				y = stoneEnemy[i].getM_mapy();

				stoneEnemy[i].destroy();
				stoneEnemy[i].setIsDeleted(true);

				ex.setPosx((x + 1) * P_SIZE - 2 + MAP_BORDER_X_MIN);
				ex.setPosy(y * P_SIZE + MAP_BORDER_Y_MIN);
				ex.Init(ResourceManager::getInstance()->getExplodeImage(0));
				explode.push_back(ex);
			}

		}

		for (int i = 0; i < unRock.size(); i++) {
			if (unRock[i].getIsDeleted() == false)
			{
				x = unRock[i].getM_mapx();
				y = unRock[i].getM_mapy();

				unRock[i].destroy();
				unRock[i].setIsDeleted(true);

				ex.setPosx((x + 1) * P_SIZE - 2 + MAP_BORDER_X_MIN);
				ex.setPosy(y * P_SIZE + MAP_BORDER_Y_MIN);
				ex.Init(ResourceManager::getInstance()->getExplodeImage(0));
				explode.push_back(ex);
			}
		}

		for (int i = 0; i < Rock.size(); i++) {
			if (Rock[i].getIsDeleted() == false)
			{
				x = Rock[i].getM_mapx();
				y = Rock[i].getM_mapy();

				Rock[i].destroy();
				Rock[i].setIsDeleted(true);

				ex.setPosx((x + 1) * P_SIZE - 2 + MAP_BORDER_X_MIN);
				ex.setPosy(y * P_SIZE + MAP_BORDER_Y_MIN);
				ex.Init(ResourceManager::getInstance()->getExplodeImage(0));
				explode.push_back(ex);
			}
		}
	}
};

GameManager* GameManager::s_Instance = nullptr;
