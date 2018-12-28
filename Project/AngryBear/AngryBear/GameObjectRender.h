#pragma once
#include "GameObject.h"
#include <iostream>

class GameObjectRender : public GameObject {
private:
	
public:
	GameObjectRender();
	~GameObjectRender();
	void Init(char *objectRender, int posx = 0, int posy = 0);
	void Update(float frameTime);
	void Render();
};
