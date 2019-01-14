#pragma once
#pragma once
#include "GameObjectRender.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Define/Define.h"
class Explode : public GameObjectRender{
private:
	const char* text;
	int i =0, j=0;
	bool expired;
public:
	void Init(const char* textureName) override
	{
		texture.loadFromFile(textureName, sf::IntRect(128*j,128*i , 128, 128));
		sprite.setTexture(texture);
		text = textureName;
		sprite.setPosition(posx, posy);

		sf::Vector2f targetSize(37, 37);
		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);
	};
	bool Update(float frameTime, int num) override {
		j ++;
		if (j == 4) {
			i++;
			j = 0;
		}
		if (i == 4) {
			expired = true;
		}
		Init(text);
		return false;
	}
	bool isExpired() {
		return expired;
	}
};
