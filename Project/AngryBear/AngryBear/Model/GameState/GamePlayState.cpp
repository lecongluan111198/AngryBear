#pragma once
#include "GamePlayState.h"
using namespace std;

int GamePlayState::levelID = 0;

GamePlayState::GamePlayState() {

}
GamePlayState::GamePlayState(bool nextLevel) {
	if (nextLevel == true)
	{
		levelID++;
	}
}

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
	}
	return false;
}