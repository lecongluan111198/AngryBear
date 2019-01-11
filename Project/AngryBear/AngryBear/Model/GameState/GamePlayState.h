#pragma once
#include<iostream>
#include <queue>
#include "../Background.h"
#include "../GameManager.h"
#include "State.h"
#include "SFML\Graphics.hpp"
using namespace std;

class GamePlayState : public State {

public:
	void Init();
	void HandleInit(int key);
	void Update(float dt, int key);
	void Render(sf::RenderWindow &window);
	bool isComplete();
};

void GamePlayState::Init() {
	GameManager::getInstance()->Init();
}
void GamePlayState::HandleInit(int key) {

}
void GamePlayState::Update(float dt, int key) {
	GameManager::getInstance()->Update(dt, key);
}
void GamePlayState::Render(sf::RenderWindow &window) {
	GameManager::getInstance()->Render(window);
}

bool GamePlayState::isComplete() {
	return false;
}