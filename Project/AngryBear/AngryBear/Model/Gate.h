#pragma once
#include "GameObjectRender.h"
#include <iostream>
#include "SFML/Graphics.hpp"
class Gate: public GameObjectRender {
public:
	void Init(const char* textureName) override
	{
		texture.loadFromFile(textureName);
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);

		sf::Vector2f targetSize((P_SIZE-2)*3, (P_SIZE-2)*3);

		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);
	};
};