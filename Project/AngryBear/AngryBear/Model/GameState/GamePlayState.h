#pragma once
#include<iostream>
#include <queue>
#include "../GameManager.h"
#include "State.h"
#include "SFML\Graphics.hpp"
#include "NextLevelState.h"
using namespace std;

class GamePlayState : public State {
private:
	static int levelID;
public:
	GamePlayState() {

	}
	GamePlayState(bool nextLevel) {
		if(nextLevel == true)
			levelID++;
	}
	void Init();
	void HandleInit(int key);
	void Update(float dt, int key);
	void Render(sf::RenderWindow &window);
	bool isComplete();
	void UpdateClickEvent(float dt, Vector2f mouse);
};

int GamePlayState::levelID = 0;

void GamePlayState::Init() {
	GameManager::getInstance()->Init(levelID);
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
	if (GameManager::getInstance()->getIsComplete() == WIN)
	{
		StateMachine::getInstance()->AddState(new NextLevelState(), true);
		//return true;
	}
	return false;
}