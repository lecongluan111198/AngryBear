#pragma once
#include "Enemy.h"
#include <iostream>
#include "SFML/Graphics.hpp"

class Stone : public Enemy {
private:
	int m_color;
	bool m_isKey;
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
		texture = t;
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);

		sf::Vector2f targetSize(50.0f, 50.0f);

		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);
	}

	bool Update(float frameTime, int num){
		bool flat = false;
		switch (num) {
		case Keyboard::Left:
			if (posx - 50 >= MAP_BORDER_X_MIN && Background::m_map[m_mapx - 1][m_mapy] == 0) {
				Background::m_map[m_mapx][m_mapy] = 0;
				posx -= 50;
				m_mapx--;
				flat = true;
			}
			break;
		case Keyboard::Right:

			if (posx + 100 <= MAP_BORDER_X_MAX && Background::m_map[m_mapx + 1][m_mapy] == 0) {
				Background::m_map[m_mapx][m_mapy] = 0;
				posx += 50;
				m_mapx++;
				flat = true;
			}
			break;
		case Keyboard::Up:
			if (posy - 50 >= MAP_BORDER_Y_MIN && Background::m_map[m_mapx][m_mapy - 1] == 0) {
				Background::m_map[m_mapx][m_mapy] = 0;
				posy -= 50;
				m_mapy--;
				flat = true;
			}
			break;
		case Keyboard::Down:
			if (posy + 100 <= MAP_BORDER_Y_MAX && Background::m_map[m_mapx][m_mapy + 1] == 0) {
				Background::m_map[m_mapx][m_mapy] = 0;
				posy += 50;
				m_mapy++;
				flat = true;
			}
			break;
		default:
			break;
		}
		Background::m_map[m_mapx][m_mapy] = m_color;
		sprite.setPosition(posx, posy);

		return flat;
	};
	int getColor() { return m_color; };
	void setColor(int color) { m_color = color; };
	bool getIsKey() { return m_isKey; };
	void setIsKey(bool key) { m_isKey = key; };
};

