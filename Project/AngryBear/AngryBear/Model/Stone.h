#pragma once
#include "Enemy.h"
#include <iostream>
#include "SFML/Graphics.hpp"

class Stone : public Enemy {
private:
	int m_color;
	bool m_isKey = false;
	bool m_isDestroy = false;
public:
	void Init(const char* textureName) override
	{
		texture.loadFromFile(textureName);
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);

		sf::Vector2f targetSize(P_SIZE, P_SIZE);

		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);
	};

	bool Update(float frameTime, int num){
		bool flat = false;
		switch (num) {
		case Keyboard::Left:
			if (posx - P_SIZE >= MAP_BORDER_X_MIN && (GameMap::m_map[m_mapx - 1][m_mapy] == BOOM_ID||GameMap::m_map[m_mapx - 1][m_mapy] == 0)) {
				GameMap::m_map[m_mapx][m_mapy] = 0;
				posx -= P_SIZE - 2;
				m_mapx--;
				flat = true;
			}
			break;
		case Keyboard::Right:

			if (posx + P_SIZE*2 <= MAP_BORDER_X_MAX && (GameMap::m_map[m_mapx + 1][m_mapy] == BOOM_ID ||GameMap::m_map[m_mapx + 1][m_mapy] == 0)) {
				GameMap::m_map[m_mapx][m_mapy] = 0;
				posx += P_SIZE - 2;
				m_mapx++;
				flat = true;
			}
			break;
		case Keyboard::Up:
			if (posy - P_SIZE >= MAP_BORDER_Y_MIN && (GameMap::m_map[m_mapx][m_mapy - 1] == BOOM_ID ||GameMap::m_map[m_mapx][m_mapy - 1] == 0)) {
				GameMap::m_map[m_mapx][m_mapy] = 0;
				posy -= P_SIZE;
				m_mapy--;
				flat = true;
			}
			break;
		case Keyboard::Down:
			if (posy + P_SIZE*2 <= MAP_BORDER_Y_MAX && (GameMap::m_map[m_mapx][m_mapy + 1] == BOOM_ID ||GameMap::m_map[m_mapx][m_mapy + 1] == 0)) {
				GameMap::m_map[m_mapx][m_mapy] = 0;
				posy += P_SIZE;
				m_mapy++;
				flat = true;
			}
			break;
		default:
			break;
		}
		if (GameMap::m_map[m_mapx][m_mapy] == BOOM_ID)
		{
			m_isKey = false;
			destroy();
			isDeleted = true;
		}
		else {
			GameMap::m_map[m_mapx][m_mapy] = m_color;
		}
	
		sprite.setPosition(posx, posy);

		return flat;
	};
	void destroy() {
		if(m_isKey) 
			GameMap::m_map[m_mapx][m_mapy] = KEY_ID;
		else
			GameMap::m_map[m_mapx][m_mapy] = 0;
	}
	int getColor() { return m_color; };
	void setColor(int color) { m_color = color; };
	bool getIsKey() { return m_isKey; };
	void setIsKey(bool key) { m_isKey = key; };/*
	bool getIsDestroy() { return m_isDestroy; };*/
};

