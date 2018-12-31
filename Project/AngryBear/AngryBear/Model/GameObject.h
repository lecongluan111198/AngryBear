#pragma once
#include "SFML/Graphics.hpp"
class GameObject {

public:
	virtual void Init(const char* textureName = "") = 0;
	virtual void Update(float frameTime) = 0;
	virtual void Render(sf::RenderWindow &window) = 0;
};
