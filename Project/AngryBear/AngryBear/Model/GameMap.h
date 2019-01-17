#pragma once
#include "GameObject.h"
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
using namespace std;
class GameMap : public GameObject {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	int posx = 0, posy = 0;
	
	
public:
	static vector<vector<int>> m_map;

	void Init(const char* textureName)
	{
		texture.loadFromFile(textureName);
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);

		sf::Vector2f targetSize(400.0f, 700.0f);

		sprite.setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);

	};

	bool Update(float frameTime, int num) { return true; };
	void Render(sf::RenderWindow &window)
	{
		window.draw(sprite);
	}
	static void resizeMap() {
		m_map.clear();
		m_map.resize(MAX_MAP_COL + 1, vector<int>());
		for (int i = 0; i < MAX_MAP_COL + 1; i++) {
			m_map[i].resize(MAX_MAP_ROW + 1, 0);
		}
	 }
	static void setPos(int x, int y, int type) {
		m_map[x][y] = type;
	}
	

};

vector<vector<int>> GameMap::m_map = vector<vector<int>>();


