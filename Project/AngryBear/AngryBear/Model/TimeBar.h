#pragma once
#include "GameObjectRender.h"
#include <iostream>
#include "SFML/Graphics.hpp"
class TimeBar : public GameObjectRender {
private:
	const char* m_text;
	int i = 0, j = 0;
public:
	void Init(const char* textureName) override
	{
		m_text = textureName;
		texture.loadFromFile(textureName, sf::IntRect(238*i, 74*j, 238, 74));
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);

		sf::Vector2f targetSize(200, 37);

		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);
	};
	bool Update(float frameTime, int num) override {
		/*j++;
		if (j == 4) {
			i++;
			j = 0;
		}
		else if (i == 4) {
			i = 0;
		}
		Init(m_text);*/
		return false;
	};
};