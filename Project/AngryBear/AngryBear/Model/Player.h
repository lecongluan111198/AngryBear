#pragma once
#pragma once
#include "GameObjectRender.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Define/Define.h"
#include "Background.h"
using namespace sf;
class Player : public GameObjectRender {
private:
	int m_color;
	//1: destroy hàng dọc, 2: destroy hàng ngang, 0: clear
	int m_onDestroy = 0;
	bool isGetKey = false;
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
	/*void test(Texture t) {
		
		texture.loadFromFile("resources/a2.png");
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);

		sf::Vector2f targetSize(P_SIZE, P_SIZE);

		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);
	}*/
	bool Update(float frameTime,int num) override {
		switch (num) {
		case Keyboard::Left:
			if (posx - P_SIZE >= MAP_BORDER_X_MIN) {
				posx -= P_SIZE -2;
				Background::m_map[m_mapx][m_mapy] = 0;
				m_mapx--;
				if (m_mapy - 1 >= 0&&Background::m_map[m_mapx][m_mapy-1] == m_color) {
					if (m_mapy + 1 < 12 && Background::m_map[m_mapx][m_mapy + 1] == m_color)
						//destroy the hang doc
						m_onDestroy = 1;
				}
			}
			break;
		case Keyboard::Right:
			
			if (posx + P_SIZE*2 <= MAP_BORDER_X_MAX) {
				posx += P_SIZE -2;
				Background::m_map[m_mapx][m_mapy] = 0;
				m_mapx++;
				if (m_mapy - 1 >= 0 && Background::m_map[m_mapx][m_mapy - 1] == m_color) {
					if (m_mapy + 1 < 12 && Background::m_map[m_mapx][m_mapy + 1] == m_color)
						//destroy the hang doc
						m_onDestroy = 1;
				}
			}
			break;
		case Keyboard::Up:
			if (posy - P_SIZE >= MAP_BORDER_Y_MIN) {
				posy -= P_SIZE;
				Background::m_map[m_mapx][m_mapy] = 0;
				m_mapy--;
				if (m_mapx - 1 >= 0 && Background::m_map[m_mapx-1][m_mapy] == m_color) {
 					if (m_mapx + 1 < 10 && Background::m_map[m_mapx + 1][m_mapy] == m_color)
						//destroy the hang ngang
						m_onDestroy = 2;
				}
			}
			break;
		case Keyboard::Down:
			if (posy + P_SIZE*2 <= MAP_BORDER_Y_MAX) {
				posy += P_SIZE;
				Background::m_map[m_mapx][m_mapy] = 0;
				m_mapy++;
				if (m_mapx - 1 >= 0 && Background::m_map[m_mapx - 1][m_mapy] != 0 && Background::m_map[m_mapx - 1][m_mapy] < 4) {
					if (m_mapx + 1 < 10 && Background::m_map[m_mapx + 1][m_mapy] != 0 && Background::m_map[m_mapx + 1][m_mapy] < 4)
						m_onDestroy = 2;
				}
			}
			break;
		default:
			break;
		}
		if (Background::m_map[m_mapx][m_mapy] == KEY_ID)
		{
			isGetKey = true;
		}
		else {
			Background::m_map[m_mapx][m_mapy] = PLAYER_ID;
		}
		sprite.setPosition(posx, posy);
		return true;
	};
	void UpdateColor(float dt,char* Texture) {
		
		texture.loadFromFile(Texture);
		sprite.setTexture(texture);
	};
	void changeColor() {
		m_color++;
		if (m_color > 4) {
			m_color = 1;
		}
	}
	int getColor() { return m_color; };
	void setColor(int color) { m_color = color; };
	Sprite getSpite() {
		return sprite;
	}

	int getDestroy() {
		return m_onDestroy;
	}
	void setDestroy(int des) {
		m_onDestroy = des;
	}

};