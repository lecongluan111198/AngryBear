#pragma once
#include <iostream>
#include <stack>

#include "SFML/Graphics.hpp"
#include "State.h"
#include "LoadingState.h"
#include "GamePlayState.h"
#include "../ResourceManager.h"

using namespace std;

class StateMachine {
private:
	queue<State*> m_states;
	State* m_newState;
	/*bool m_isRemoving;
	bool m_isAdding;
	bool m_isReplacing;*/
	sf::RenderWindow window;
	static StateMachine* s_Instance;
	StateMachine(){
		State* test = new LoadingState();
		m_states.push(test);
		test = new GamePlayState();
		m_states.push(test);
	}
public:
	static::StateMachine* getInstance();
	void AddState(State* newState);
	void RemoveState();
	void SwitchState();
	State* &GetActiveState();
	void Init();
	void Update(float dt, int key);
	void Render(sf::RenderWindow &window);
}; 

StateMachine* StateMachine::s_Instance = NULL;

StateMachine* StateMachine::getInstance() {
	if (s_Instance == NULL)
		s_Instance = new StateMachine();
	return s_Instance;
}

void StateMachine::AddState(State* newState) {
	m_states.push(move(newState)); //move all resource from newState to this->newState
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
	m_states.front()->Init();
}

void StateMachine::Update(float dt, int key) {
	m_states.front()->Update(dt, key);
}

void StateMachine::Render(sf::RenderWindow &window) {
	m_states.front()->Render(window);

	if (m_states.front()->isComplete())
	{
		RemoveState();
		SwitchState();
	}
}