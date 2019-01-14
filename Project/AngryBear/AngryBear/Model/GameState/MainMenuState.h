#pragma once
#include<iostream>
#include <queue>
#include "../Widget.h"
#include "../ResourceManager.h"
#include "State.h"
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
		widget->setPos(0, WINDOWS_H / 2);
		widget->setSize(WINDOWS_W, 30);
		widget->setImage(TEXTURE_PLAY_BUTTON);
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

	ResourceManager::getInstance()->Init();
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

	if (_clock.getElapsedTime().asSeconds() > 1 && m_nLoadFile >= 1)
	{
		isCheck = true;
	}
}

bool MainMenuState::isComplete() {

	return isCheck;
}

void MainMenuState::UpdateClickEvent(float dt, Vector2f mouse) {
	
}