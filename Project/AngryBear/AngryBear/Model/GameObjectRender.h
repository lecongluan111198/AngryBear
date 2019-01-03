#pragma once
#include "GameObject.h"
#include <iostream>
#include "SFML/Graphics.hpp"

class GameObjectRender : public GameObject {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	int posx = 0, posy = 0;
	int m_mapx, m_mapy;
public:
	
	void Init(const char* textureName)
	{
		texture.loadFromFile(textureName);
		sprite.setTexture(texture);
		sprite.setPosition(posx, posy);
	};
	
	virtual bool Update(float frameTime, int num) { return false; };
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


	int getM_mapx() {
		return m_mapx;
	}
	void setM_mapx(int M_mapx) {
		m_mapx = M_mapx;
	}
	int getM_mapy() {
		return m_mapy;
	}
	void setM_mapy(int M_mapy) {
		m_mapy = M_mapy;
	}

};
