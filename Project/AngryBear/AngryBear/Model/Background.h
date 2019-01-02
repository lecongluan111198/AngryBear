#pragma once
#include "GameObject.h"
#include <iostream>
#include "SFML/Graphics.hpp"

class Background : public GameObject {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	int posx = 0, posy = 0;
public:
	void Init(const char* textureName)
	{
		texture.loadFromFile(textureName);
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);

		sf::Vector2f targetSize(500.0f, 600.0f);

		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);

	};

	void Update(float frameTime, int num) {};
	void Render(sf::RenderWindow &window)
	{
		window.draw(sprite);
	}
};
