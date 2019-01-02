#pragma once
#pragma once
#include "GameObjectRender.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Define/Define.h"
using namespace sf;
class Player : public GameObjectRender {
private:
	int m_color;
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

		dir = 1;
	};
	void Update(float frameTime,int num) override {
		switch (num) {
		case Keyboard::Left:
			if (posx - 50 >= MAP_BORDER_X_MIN) {
				posx -= 50;
			}
			break;
		case Keyboard::Right:
			
			if (posx + 100 <= MAP_BORDER_X_MAX) {
				posx += 50;
			}
			break;
		case Keyboard::Up:
			if (posy - 50 >= MAP_BORDER_Y_MIN) {
				posy -= 50;
			}
			break;
		case Keyboard::Down:
			if (posy + 100 <= MAP_BORDER_Y_MAX) {
				posy += 50;
			}
			break;
		default:
			break;
		}
		

		sprite.setPosition(posx, posy);
	};
	int getColor() { return m_color; };
	void setColor(int color) { m_color = color; };

};