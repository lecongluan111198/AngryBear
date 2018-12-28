#pragma once
#pragma once
#include "GameObjectRender.h"
#include <iostream>
#include "SFML/Graphics.hpp"

class Player : public GameObjectRender {
private:
	int m_color;
public:
	void Update(float frameTime) override {};
	int getColor() { return m_color; };
	void setColor(int color) { m_color = color; };

};