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
	int posx = 0, posy = 0;
	static vector<vector<int>> m_map;
	
public:
	Background() {
		
	}
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
	static void resizeMap() {
		m_map.resize(5, vector<int>());
		for (int i = 0; i < 5; i++) {
			m_map[i].resize(5, 0);
		}
	 }
	static void setPos(int x, int y, int type) {
		m_map[x][y] = type;
	}

};


