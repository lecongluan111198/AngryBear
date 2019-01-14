#pragma once
#include<iostream>
#include <queue>
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
	void UpdateClickEvent(float dt, Vector2f mouse);
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

void GamePlayState::UpdateClickEvent(float dt, Vector2f mouse) {
	GameManager::getInstance()->UpdateClickEvent(dt, mouse);
}

bool GamePlayState::isComplete() {
	return false;
}