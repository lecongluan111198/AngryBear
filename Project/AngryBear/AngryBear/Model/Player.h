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
	int m_color = 1;
public:
	void Init(const char* textureName) override
	{
		texture.loadFromFile(textureName);
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);

		sf::Vector2f targetSize(50.0f, 50.0f);

		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);
	};
	void test(Texture t) {
		
		texture.loadFromFile("resources/a2.png");
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);

		sf::Vector2f targetSize(50.0f, 50.0f);

		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);
	}
	bool Update(float frameTime,int num) override {
		switch (num) {
		case Keyboard::Left:
			if (posx - 50 >= MAP_BORDER_X_MIN) {
				posx -= 50;
				Background::m_map[m_mapx][m_mapy] = 0;
				m_mapx--;
				if (m_mapy - 1 >= 0&&Background::m_map[m_mapx][m_mapy-1] !=0 && Background::m_map[m_mapx][m_mapy - 1] < 4) {
					if (m_mapy + 1 < 12 && Background::m_map[m_mapx][m_mapy + 1] != 0 && Background::m_map[m_mapx][m_mapy + 1] < 4)
						printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
				}
			}
			break;
		case Keyboard::Right:
			
			if (posx + 100 <= MAP_BORDER_X_MAX) {
				posx += 50;
				Background::m_map[m_mapx][m_mapy] = 0;
				m_mapx++;
				if (m_mapy - 1 >= 0 && Background::m_map[m_mapx][m_mapy - 1] != 0 && Background::m_map[m_mapx][m_mapy - 1] <4) {
					if (m_mapy + 1 < 12 && Background::m_map[m_mapx][m_mapy + 1] != 0 && Background::m_map[m_mapx][m_mapy + 1] < 4)
						printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
				}
			}
			break;
		case Keyboard::Up:
			if (posy - 50 >= MAP_BORDER_Y_MIN) {
				posy -= 50;
				Background::m_map[m_mapx][m_mapy] = 0;
				m_mapy--;
				if (m_mapx - 1 >= 0 && Background::m_map[m_mapx-1][m_mapy] != 0 && Background::m_map[m_mapx - 1][m_mapy] < 4) {
					if (m_mapx + 1 < 10 && Background::m_map[m_mapx+1][m_mapy] != 0 && Background::m_map[m_mapx + 1][m_mapy] < 4)
						printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
				}
			}
			break;
		case Keyboard::Down:
			if (posy + 100 <= MAP_BORDER_Y_MAX) {
				posy += 50;
				Background::m_map[m_mapx][m_mapy] = 0;
				m_mapy++;
				if (m_mapx - 1 >= 0 && Background::m_map[m_mapx - 1][m_mapy] != 0 && Background::m_map[m_mapx - 1][m_mapy] < 4) {
					if (m_mapx + 1 < 10 && Background::m_map[m_mapx + 1][m_mapy] != 0 && Background::m_map[m_mapx + 1][m_mapy] < 4)
						printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
				}
			}
			break;
		default:
			break;
		}
		Background::m_map[m_mapx][m_mapy] = PLAYER_ID;
		sprite.setPosition(posx, posy);
		return true;
	};
	void UpdateColor(float dt) {
		m_color++;
		if (m_color > 3)
			m_color = 0;

		/*texture.loadFromFile(color[m_color]);
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);*/
		
	};
	int getColor() { return m_color; };
	void setColor(int color) { m_color = color; };
	Sprite getSpite() {
		return sprite;
	}

};