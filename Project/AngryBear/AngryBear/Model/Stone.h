#pragma once
#include "Enemy.h"
#include <iostream>
#include "SFML/Graphics.hpp"

class Stone : public Enemy {
private:
	int m_color;
	bool m_isKey;
public:
	void Update(float frameTime) override{};
	int getColor() { return m_color; };
	void setColor(int color) { m_color = color; };
	bool getIsKey() { return m_isKey; };
	void setIsKey(bool key) { m_isKey = key; };
};

