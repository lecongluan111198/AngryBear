#pragma once
#include "GameObjectRender.h"
#include <iostream>
#include "SFML/Graphics.hpp"
class TimeBar : public GameObjectRender {
private:
	const char* m_text;
	int imageX = 0, imageY = 0;
	int startTime;
public:
	void Init(const char* textureName) override
	{
		startTime = -1;
		m_text = textureName;
		texture.loadFromFile(textureName, sf::IntRect(238* imageX, 74* imageY, 238, 74));
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);

		sf::Vector2f targetSize(200, 37);

		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);
	};
	bool Update(float frameTime, int num) override {
		
		if (startTime == -1)
			startTime = frameTime;
		if ((frameTime - startTime) / 8 == imageX + 1)
		{
			if (imageX + 1 >= 4)
			{
				if (imageY + 1 >= 4)
				{
					imageX = 0;
					imageY++;
				}
			}
			else
			{
				imageX++;
			}
			texture.loadFromFile(m_text, sf::IntRect(238 * imageX, 74 * imageY, 238, 74));
			sprite.setTexture(texture);
			sprite.setPosition(posx, posy);

			sf::Vector2f targetSize(200, 37);

			sprite.setScale(
				targetSize.x / sprite.getLocalBounds().width,
				targetSize.y / sprite.getLocalBounds().height);
		}

		return false;
	};

	bool Update(float frameTime, int num, int second) {
		if (second / 8 == imageX + 1)
		{
			if (imageX + 1 >= 4)
			{
				if(imageY + 1 >= 4)
				imageX = 0;
				imageY++;
			}
			else
				imageX++;
			texture.loadFromFile(m_text, sf::IntRect(238 * imageX, 74 * imageY, 238, 74));
			sprite.setTexture(texture);
			sprite.setPosition(posx, posy);

			sf::Vector2f targetSize(200, 37);

			sprite.setScale(
				targetSize.x / sprite.getLocalBounds().width,
				targetSize.y / sprite.getLocalBounds().height);
		}

		return false;
	};
};