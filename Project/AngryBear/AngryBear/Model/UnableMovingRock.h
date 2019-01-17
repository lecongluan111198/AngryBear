#pragma once
#include "Rock.h"
#include <iostream>
#include "SFML/Graphics.hpp"
class UnableMovingRock : public Rock{
public:
	void Init(const char* textureName)
	{
		texture.loadFromFile(textureName, sf::IntRect(45, 400, 330, 330));
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);

		sf::Vector2f targetSize(P_SIZE - 2, P_SIZE);

		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);
	};
	bool Update(float frameTime, int num) {
		return false;
	}
};
