#pragma once
#include "Enemy.h"
#include <iostream>
#include "SFML/Graphics.hpp"

class Stone : public Enemy {
private:
	int m_color;
	bool m_isKey;
public:
	Stone() {
		posx = 100;
		posy = 100;
	}
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

	bool Update(float frameTime, int num){
		bool flat = false;
		switch (num) {
		case Keyboard::Left:
			if (posx - 50 >= MAP_BORDER_X_MIN) {
				posx -= 50;
				m_mapx--;
				flat = true;
			}
			break;
		case Keyboard::Right:

			if (posx + 100 <= MAP_BORDER_X_MAX) {
				posx += 50;
				m_mapx++;
				flat = true;
			}
			break;
		case Keyboard::Up:
			if (posy - 50 >= MAP_BORDER_Y_MIN) {
				posy -= 50;
				m_mapy--;
				flat = true;
			}
			break;
		case Keyboard::Down:
			if (posy + 100 <= MAP_BORDER_Y_MAX) {
				posy += 50;
				m_mapy++;
				flat = true;
			}
			break;
		default:
			break;
		}
		sprite.setPosition(posx, posy);

		return flat;
	};
	int getColor() { return m_color; };
	void setColor(int color) { m_color = color; };
	bool getIsKey() { return m_isKey; };
	void setIsKey(bool key) { m_isKey = key; };
};

