#pragma once
#include "GameObjectRender.h"
#include <iostream>
#include "../Define/Define.h"
#include "SFML/Graphics.hpp"
class TimeBar : public GameObjectRender {
private:
	const char* m_text;
	int imageX = 0, imageY = 0;
	int nImage = 0;
	int startTime;
public:
	void Init(const char* textureName) override
	{
		startTime = -1;
		nImage = 0;
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
		std::cout << "Start time: " <<startTime << std::endl;
		std::cout << "Frame time: " << frameTime << std::endl;
		std::cout << "Image: " << nImage << std::endl;
		std::cout << "imageX: " << imageX << std::endl;
		std::cout << "imageY: " << imageY << std::endl;
		std::cout << std::endl;
		if (((int)frameTime - startTime) / 8 >= nImage + 1)
		{
			if (nImage < 16)
			{
				if (imageX + 1 >= 4)
				{
					imageX = 0;
					imageY++;
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
			nImage++;
		}

		return false;
	};
	int getStartTime() {
		return startTime;
	}

};