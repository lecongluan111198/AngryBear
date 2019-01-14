#pragma once
#pragma once
#include "GameObjectRender.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Define/Define.h"
class Explode : public GameObjectRender {
private:
	int posx = 0, posy = 0;
	const char* text;
public:
	void Init(const char* textureName) override
	{
		/*texture.loadFromFile(textureName, sf::IntRect(128*posx, 128*posy, 128, 128));
		sprite.setTexture(texture);
		text = textureName;
		sprite.setPosition(posx, posy);

		sf::Vector2f targetSize(37, 37);
		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);*/
	};
	bool Update(float frameTime, int num) override {
		/*posx++;
		if (posx == 4) {
			posy++;
			posx = 0;
		}
		Init(text);*/
	}
};
