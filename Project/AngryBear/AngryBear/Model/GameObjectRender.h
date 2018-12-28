#pragma once
#include "GameObject.h"
#include <iostream>
#include "SFML/Graphics.hpp"

class GameObjectRender : public GameObject {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	int dir = 0;
public:
	void Init(const char* textureName, int pos_x , int pos_y)
	{
		texture.loadFromFile(textureName);
		sprite.setTexture(texture);
		sprite.setPosition(pos_x, pos_y);
		dir = 1;
	};
	void Update(float frameTime){};
	void Render(sf::RenderWindow &window)
	{
		window.draw(sprite);
	}
};
