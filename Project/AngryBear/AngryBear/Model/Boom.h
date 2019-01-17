#pragma once
#include "GameObjectRender.h"
#include <iostream>
#include "SFML/Graphics.hpp"
class Boom :public GameObjectRender {
private:
	bool isExplode = false;
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
	void setIsExplode(bool ex) {
		isExplode = ex;
	}
	bool getIsExplode() { return isExplode; }
};
