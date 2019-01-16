#pragma once
#include<iostream>
#include <queue>
#include "MainMenuState.h"
#include "../Widget.h"
#include "../ResourceManager.h"
#include "State.h"
#include "SFML\Graphics.hpp"
#include "StateMachine.h"



using namespace std;

class LoadingState : public State {
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
		widget->setImage(TEXTURE_LOGO);

		m_WidgetQueue.push(widget);
		
		/*widget = new Widget();
		widget->setPos(0, WINDOWS_H / 2);
		widget->setSize(WINDOWS_W, 30);


		m_WidgetQueue.push(widget);*/
	}

public:
	~LoadingState() {
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
	
};

void LoadingState::Init() {
	
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
void LoadingState::HandleInit(int key) {

}
void LoadingState::Update(float dt, int key) {
	ResourceManager::getInstance()->loadData();
	m_nLoadFile++;
}
void LoadingState::Render(sf::RenderWindow &window) {
	queue<Widget *> q = m_WidgetQueue;
	Widget* widget;
	while (!q.empty()) {
		widget = q.front();
		q.pop();
		widget->Render(window);
	}

	if (_clock.getElapsedTime().asSeconds() > 1 && m_nLoadFile >= 1)
	{
		//StateMachine *a = StateMachine::getInstance();
		StateMachine::getInstance()->AddState(new MainMenuState());

		isCheck = true;
	}
}

bool LoadingState::isComplete() {

	return isCheck;
}