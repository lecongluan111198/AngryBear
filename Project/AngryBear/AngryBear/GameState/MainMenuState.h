#pragma once
#include<iostream>
#include <queue>
#include "../Model/Widget.h"
#include "../Manager/StateMachine.h"
#include "State.h"
#include "GamePlayState.h"
#include "SFML\Graphics.hpp"
using namespace std;

class MainMenuState : public State {
private:
	queue<Widget*> m_WidgetQueue;
	sf::Clock _clock;
	int m_nLoadFile = 0;
	bool isCheck = false;
	void InitWidget() {
		Widget *widget;

		widget = new Widget();
		widget->setPos(0, 0);
		widget->setSize(WINDOWS_W, WINDOWS_H);
		widget->setImage(TEXTURE_BACKGROUND_MENU);

		m_WidgetQueue.push(widget);

		widget = new Widget();
		widget->setPos(150, 350);
		widget->setSize(100, 100);
		widget->setImage(TEXTURE_PLAY_BUTTON);
		widget->setState(new GamePlayState());
		m_WidgetQueue.push(widget);
	}

public:
	~MainMenuState() {
		while (!m_WidgetQueue.empty())
		{
			delete m_WidgetQueue.front();
			m_WidgetQueue.pop();
		}
	}
	void Init();
	void HandleInit(int key);
	void Update(float dt, int key);
	void Render(sf::RenderWindow &window);
	bool isComplete();
	void UpdateClickEvent(float dt, Vector2f mouse);
};

void MainMenuState::Init() {

	InitWidget();
	queue<Widget *> q = m_WidgetQueue;
	Widget* widget;
	while (!q.empty()) {
		widget = q.front();
		q.pop();
		widget->Init();
	}
}
void MainMenuState::HandleInit(int key) {

}
void MainMenuState::Update(float dt, int key) {
}
void MainMenuState::Render(sf::RenderWindow &window) {
	queue<Widget *> q = m_WidgetQueue;
	Widget* widget;
	while (!q.empty()) {
		widget = q.front();
		q.pop();
		widget->Render(window);
	}
}

bool MainMenuState::isComplete() {

	return isCheck;
}

void MainMenuState::UpdateClickEvent(float dt, Vector2f mouse) {
	queue<Widget *> q = m_WidgetQueue;
	Widget* widget;
	while (!q.empty()) {
		widget = q.front();
		q.pop();
		sf::FloatRect bounds = widget->getSprite().getGlobalBounds();

		if (bounds.contains(mouse) && widget->getState() != NULL)
		{
			StateMachine::getInstance()->AddState(widget->getState());
			isCheck = true;
		}
	}
}