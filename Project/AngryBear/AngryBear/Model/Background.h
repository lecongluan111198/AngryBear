#pragma once
#include "GameObject.h"
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
using namespace std;
class Background : public GameObject {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	int posX = 0, posY = 0;
	int sizeX = 0, sizeY = 0;
public:

	void Init(const char* textureName)
	{
		texture.loadFromFile(textureName);
		sprite.setTexture(texture);
		sprite.setPosition(posX, posX);

		sf::Vector2f targetSize(sizeX, sizeY);

		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);

	};

	bool Update(float frameTime, int num) { return true; };
	void Render(sf::RenderWindow &window)
	{
		window.draw(sprite);
	}

	void setSize(int sizeX, int sizeY) {
		this->sizeX = sizeX;
		this->sizeY = sizeY;
	}
	void setPos(int posX, int posY) {
		this->posX = posX;
		this->posY = posY;
	}

};



