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
	stack<State*> m_states;
	State* m_newState;
	bool m_isRemoving;
	bool m_isAdding;
	bool m_isReplacing;
	static StateMachine* s_Instance;
	StateMachine() {

	}
public:
	static::StateMachine* getInstance();
	void AddState(State* newState, bool isReplacing = true);
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

void StateMachine::AddState(State* newState, bool isReplacing) {
	this->m_isAdding = true;
	this->m_isReplacing = isReplacing;
	
	this->m_newState = move(newState); //move all resource from newState to this->newState
}

void StateMachine::RemoveState() {
	this->m_isRemoving = true;
}

void StateMachine::SwitchState() {
	if (this->m_isRemoving && !this->m_states.empty()) {
		this->m_states.pop();

		if (!this->m_states.empty())
		{
			this->m_states.top()->Resume();
		}
		this->m_isRemoving = false;
	}

	if (this->m_isAdding) {
		if (!this->m_states.empty())
		{
			this->m_states.pop();
		}
		else {
			this->m_states.top()->Pause();
		}

		this->m_states.push(move(this->m_newState));
		this->m_states.top()->Init();
		this->m_isAdding = false;
	}
}

State* &StateMachine::GetActiveState() {
	return this->m_states.top();
}

void StateMachine::Init() {
	LoadingState* test1 = new LoadingState();
	
	test1->InitWidget();
	test1->Init();
	m_states.push(test1);
	//GamePlayState* test2 = new GamePlayState();
	//test2->Init();
	//m_states.push(test2);
}

void StateMachine::Update(float dt, int key) {
	stack<State*> s = m_states;
	State* state;
	while (!s.empty()) {
		state = s.top();
		s.pop();
		state->Update(dt, key);
	}
}

void StateMachine::Render(sf::RenderWindow &window) {
	stack<State*> s = m_states;
	State* state;
	while (!s.empty()) {
		state = s.top();
		s.pop();
		state->Render(window);
	}
}