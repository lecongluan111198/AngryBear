#pragma once
#include<iostream>
#include <queue>
#include "../Model/Widget.h"
#include "../Manager/ResourceManager.h"
#include "../Manager/GameManager.h"
#include "State.h"
#include "SFML\Graphics.hpp"

using namespace std;
class GameOverState : public State {
private:
	Widget *Background;
	Widget *Title;
	Widget *TitleGameOVer;
	Widget *RetryButton;

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

		TitleGameOVer = new Widget();
		TitleGameOVer->setPos(100, 100);
		TitleGameOVer->setSize(200, 150);
		TitleGameOVer->setImage(TEXTURE_GAMEOVER);

		RetryButton = new Widget();
		RetryButton->setPos(175, 300);
		RetryButton->setSize(50, 50);
		RetryButton->setImage(TEXTURE_PLAYAGAIN);
	}

public:
	~GameOverState() {
		delete Background;
		delete Title;
		delete RetryButton;
		delete TitleGameOVer;
	}
	void Init();
	void HandleInit(int key);
	void Update(float dt, int key);
	void Render(sf::RenderWindow &window);
	void UpdateClickEvent(float dt, Vector2f mouse);
	bool isComplete();

};

void GameOverState::Init() {

	InitWidget();

	Background->Init();
	Title->Init();
	RetryButton->Init();
	TitleGameOVer->Init();
}
void GameOverState::HandleInit(int key) {

}
void GameOverState::Update(float dt, int key) {
}
void GameOverState::Render(sf::RenderWindow &window) {

	Background->Render(window);
	Title->Render(window);
	RetryButton->Render(window);
	TitleGameOVer->Render(window);
}

void GameOverState::UpdateClickEvent(float dt, Vector2f mouse) {

	sf::FloatRect RetryBtnBounds = RetryButton->getSprite().getGlobalBounds();
	if (RetryBtnBounds.contains(mouse))
	{
		isCheck = true;
	}
}

bool GameOverState::isComplete() {

	return isCheck;
}

