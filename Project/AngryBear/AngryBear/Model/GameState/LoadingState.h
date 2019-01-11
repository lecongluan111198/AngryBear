#pragma once
#include<iostream>
#include <queue>
#include "../Background.h"
#include "../ResourceManager.h"
#include "State.h"
#include "SFML\Graphics.hpp"
using namespace std;

class LoadingState : public State {
private:
	queue<Background*> m_WidgetQueue;

public:
	void Init();
	void HandleInit(int key);
	void Update(float dt, int key);
	void Render(sf::RenderWindow &window);
	void InitWidget() {
		Background *background;
		
		background = new Background();
		background->setPos(0, 0);
		background->setSize(WINDOWS_W, WINDOWS_H);

		m_WidgetQueue.push(background);

		background = new Background();
		background->setPos(0, WINDOWS_H/2);
		background->setSize(WINDOWS_W, 30);

		m_WidgetQueue.push(background);

		//background = new Background();
		//background->setPos(0, 0);
		//background->setSize(WINDOWS_W, WINDOWS_H);

		//m_WidgetQueue.push(background);
	}
};

void LoadingState::Init() {
	queue<Background *> q = m_WidgetQueue;
	Background* background;
	while (!q.empty()) {
		background = q.front();
		q.pop();
		background->Init(TEXTURE_BG);
	}

	ResourceManager::getInstance()->Init();
}
void LoadingState::HandleInit(int key) {

}
void LoadingState::Update(float dt, int key) {
	ResourceManager::getInstance()->loadData();
}
void LoadingState::Render(sf::RenderWindow &window) {
	queue<Background *> q = m_WidgetQueue;
	Background* background;
	while (!q.empty()) {
		background = q.front();
		q.pop();
		background->Render(window);
	}
}