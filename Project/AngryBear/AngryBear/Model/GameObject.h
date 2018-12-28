#pragma once
#include "SFML/Graphics.hpp"
class GameObject {

public:
	virtual void Init(const char* textureName = "", int pos_x = 0, int pos_y = 0) = 0;
	virtual void Update(float frameTime) = 0;
	virtual void Render(sf::RenderWindow &window) = 0;
};
