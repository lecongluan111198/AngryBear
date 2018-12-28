#pragma once

class GameObject {

public:
	virtual void Init(char *objectImage, int pox, int poy) = 0;
	virtual void Update(float frameTime) = 0;
	virtual void Render() = 0;
};
