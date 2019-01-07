#pragma once
#include <iostream>
#include <stack>

#include "SFML/Graphics.hpp"
#include "State.h"
#include "../ResourceManager.h"


class StateMachine {
private:
	stack<State*> m_states;
	State* m_newState;
	bool m_isRemoving;
	bool m_isAdding;
	bool m_isReplacing;

	void AddState(State* newState, bool isReplacing = true);
	void RemoveState();
	void SwitchState();
	State* &GetActiveState();
}; 

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