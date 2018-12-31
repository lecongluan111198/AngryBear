#pragma once
#include "GameObject.h"
#include <iostream>
#include "SFML/Graphics.hpp"

class GameObjectRender : public GameObject {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	int dir = 0;
	int posx = 0, posy = 0;
public:
	void Init(const char* textureName)
	{
		texture.loadFromFile(textureName);
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);
		dir = 1;
	};
	void Update(float frameTime){};
	void Render(sf::RenderWindow &window)
	{
		window.draw(sprite);
	}
	int getPosx() {
		return posx;
	}
	void setPosx(int pos_x) {
		posx = pos_x;
	}
	int getPosy() {
		return posy;
	}
	void setPosy(int pos_y) {
		posy = pos_y;
	}
};
