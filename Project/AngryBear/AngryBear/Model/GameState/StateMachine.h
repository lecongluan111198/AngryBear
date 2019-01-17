#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include "SFML/Graphics.hpp"
#include "State.h"

#include "../ResourceManager.h"

using namespace std;

class StateMachine {
private:
	queue<State*> m_states;
	State* m_newState;
	static StateMachine* s_Instance;
	bool isReplace = false;
	StateMachine(){
	}
public:
	static StateMachine* getInstance();


	void AddState(State* newState, bool isReplace = false);
	void RemoveState();
	void SwitchState();
	State* &GetActiveState();
	void Init();
	void Update(float dt, int key);
	void Render(sf::RenderWindow &window);
	void UpdateClickEvent(float dt, Vector2f mouse);
}; 

StateMachine* StateMachine::s_Instance = NULL;

StateMachine* StateMachine::getInstance() {
	if (s_Instance == NULL)
		s_Instance = new StateMachine();
	return s_Instance;
}

void StateMachine::AddState(State* newState, bool isReplace) {
	m_states.push(move(newState)); //move all resource from newState to this->newState
	if (isReplace)
	{
		State *temp = m_states.front();
		//RemoveState();
		m_states.pop();
		m_states.push(temp);
		SwitchState();
	}

	
}

void StateMachine::RemoveState() {
	if (!m_states.empty())
	{
		delete m_states.front();
		m_states.pop();
	}
}

void StateMachine::SwitchState() {
	Init(); //initialize the next state
}

State* &StateMachine::GetActiveState() {
	return this->m_states.front();
}

void StateMachine::Init() {
	if (!m_states.empty())
	{
		m_states.front()->Init();
	}
}

void StateMachine::Update(float dt, int key) {
	if (!m_states.empty())
		m_states.front()->Update(dt, key);
}

void StateMachine::Render(sf::RenderWindow &window) {
	if (!m_states.empty())
	{
		m_states.front()->Render(window);

		if (m_states.front()->isComplete())
		{
			RemoveState();
			SwitchState();
			window.clear();
		}
	}
}

void StateMachine::UpdateClickEvent(float dt, Vector2f mouse) {
	m_states.front()->UpdateClickEvent(dt, mouse);
}