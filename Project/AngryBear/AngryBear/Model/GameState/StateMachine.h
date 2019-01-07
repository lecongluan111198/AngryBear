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
	void ProcessStateChanges();
	State* &GetActiveState();
}; 
