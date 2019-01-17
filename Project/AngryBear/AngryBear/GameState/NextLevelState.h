#pragma once
#include<iostream>
#include <queue>
#include "../Model/Widget.h"
#include "../Manager/ResourceManager.h"
#include "../Manager/GameManager.h"
#include "State.h"
#include "SFML\Graphics.hpp"

using namespace std;
class NextLevelState : public State {
private:
	Widget *Background;
	Widget *Title;
	Widget *RetryButton;
	Widget *NextButton;
	
	bool isCheck = false;
	void InitWidget() {

		Background = new Widget();
		Background->setPos(0, 0);
		Background->setSize(WINDOWS_W, WINDOWS_H);
		Background->setImage(TEXTURE_BG);

		Title = new Widget();
		Title->setPos(100, 200);
		Title->setSize(200, 200);
		Title->setImage(TEXTURE_WIN);

		RetryButton = new Widget();
		RetryButton->setPos(125, 250);
		RetryButton->setSize(50, 50);
		RetryButton->setImage(TEXTURE_PLAYAGAIN);

		NextButton = new Widget();
		NextButton->setPos(225, 250);
		NextButton->setSize(50, 50);
		NextButton->setImage(TEXTURE_NEXTLEVEL);
	}

public:
	~NextLevelState() {
		delete Background;
		delete Title;
		delete RetryButton;
		delete NextButton;
	}
	void Init();
	void HandleInit(int key);
	void Update(float dt, int key);
	void Render(sf::RenderWindow &window);
	void UpdateClickEvent(float dt, Vector2f mouse);
	bool isComplete();

};

void NextLevelState::Init() {

	InitWidget();

	Background->Init();
	Title->Init();
	RetryButton->Init();
	NextButton->Init();
}
void NextLevelState::HandleInit(int key) {

}
void NextLevelState::Update(float dt, int key) {
}
void NextLevelState::Render(sf::RenderWindow &window) {

	Background->Render(window);
	Title->Render(window);
	RetryButton->Render(window);
	NextButton->Render(window);
}

void NextLevelState::UpdateClickEvent(float dt, Vector2f mouse) {

	sf::FloatRect RetryBtnBounds = RetryButton->getSprite().getGlobalBounds();
	if (RetryBtnBounds.contains(mouse))
	{
		//GamePlayState::levelID++;
		isCheck = true;
	}
		
	sf::FloatRect NextBtnBounds = NextButton->getSprite().getGlobalBounds();
	if (NextBtnBounds.contains(mouse))
	{
		GameManager::getInstance()->nextLevel();
		isCheck = true;
	}
}

bool NextLevelState::isComplete() {

	return isCheck;
}

