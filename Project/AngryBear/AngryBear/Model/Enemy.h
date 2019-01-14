#pragma once
#include "GameObjectRender.h"
#include <iostream>
#include "SFML/Graphics.hpp"
class Enemy : public GameObjectRender {
protected:
	bool isDeleted = false;
public:
	bool getIsDeleted() {
		return isDeleted;
	}
	void setIsDeleted(bool isDeleted) {
		this->isDeleted = isDeleted;
	}
};
