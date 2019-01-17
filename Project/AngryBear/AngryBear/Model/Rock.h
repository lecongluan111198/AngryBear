#pragma once
#include "Enemy.h"
#include <iostream>
#include "SFML/Graphics.hpp"
class Rock : public Enemy {
public:
	void Init(const char* textureName)
	{
		texture.loadFromFile(textureName, sf::IntRect(45, 35, 330, 330));
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);

		sf::Vector2f targetSize(P_SIZE, P_SIZE);

		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);
	};
};