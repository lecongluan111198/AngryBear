#pragma once
#include<iostream>
#include <queue>
#include "../Widget.h"
#include "../ResourceManager.h"
#include "State.h"
#include "SFML\Graphics.hpp"
#include "StateMachine.h"
#include "GamePlayState.h"



using namespace std;

class NextLevelState : public State {
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
		widget->setImage(TEXTURE_BG);
		m_WidgetQueue.push(widget);

		widget = new Widget();
		widget->setPos(100, 200);
		widget->setSize(200, 200);
		widget->setImage(TEXTURE_WIN);
		m_WidgetQueue.push(widget);

		widget = new Widget();
		widget->setPos(125, 250);
		widget->setSize(50, 50);
		widget->setImage(TEXTURE_PLAYAGAIN);
		//widget->setState(new GamePlayState());
		m_WidgetQueue.push(widget);

		widget = new Widget();
		widget->setPos(225, 250);
		widget->setSize(50, 50);
		widget->setImage(TEXTURE_NEXTLEVEL);
		//widget->setState(new GamePlayState(true));
		m_WidgetQueue.push(widget);
	}

public:
	~NextLevelState() {
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
	void UpdateClickEvent(float dt, Vector2f mouse);
	bool isComplete();

};

void NextLevelState::Init() {

	InitWidget();
	queue<Widget *> q = m_WidgetQueue;
	Widget* widget;
	while (!q.empty()) {
		widget = q.front();
		q.pop();
		widget->Init();
	}
}
void NextLevelState::HandleInit(int key) {

}
void NextLevelState::Update(float dt, int key) {
}
void NextLevelState::Render(sf::RenderWindow &window) {
	queue<Widget *> q = m_WidgetQueue;
	Widget* widget;
	while (!q.empty()) {
		widget = q.front();
		q.pop();
		widget->Render(window);
	}
}

void NextLevelState::UpdateClickEvent(float dt, Vector2f mouse) {
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

bool NextLevelState::isComplete() {

	return isCheck;
}

