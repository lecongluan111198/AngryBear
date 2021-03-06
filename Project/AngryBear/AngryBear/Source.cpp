#include <math.h>
#include <cstdlib>
#include <vector>
#include <ctime> 
#include <iostream>
#include "Manager/GameManager.h"
#include "Manager/ResourceManager.h"
#include "SFML/Graphics.hpp"
#include "Define/Define.h"
#include "Manager/StateMachine.h"
#include "GameState/LoadingState.h"
using namespace sf;
using namespace std;



int main(int argc, char** argv)
{
	srand((unsigned int)time(NULL));
	
	RenderWindow window(VideoMode(WINDOWS_W, WINDOWS_H), "Angry Bear!", Style::Default);
	window.setFramerateLimit(FPS_LIMIT);

	// ============================ Init ============================

	StateMachine::getInstance()->AddState(new LoadingState());
	StateMachine::getInstance()->Init();
	
	Clock clock;
	Time elapsed;
	int num = 0;
	sf::Vector2f mouse;
	Event event;
	while (window.isOpen())
	{
		// A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
		float dt = clock.getElapsedTime().asSeconds();
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Left))
				num = Keyboard::Left;
			else if (Keyboard::isKeyPressed(Keyboard::Right))
				num = Keyboard::Right;
			else if (Keyboard::isKeyPressed(Keyboard::Up))
				num = Keyboard::Up;
			else if (Keyboard::isKeyPressed(Keyboard::Down))
				num = Keyboard::Down;
			else if(Keyboard::isKeyPressed(Keyboard::Space))
				num = Keyboard::Space;
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				// transform the mouse position from window coordinates to world coordinates
				mouse = window.mapPixelToCoords(Mouse::getPosition(window));
				StateMachine::getInstance()->UpdateClickEvent(dt, mouse);
			}
		}

		elapsed = clock.getElapsedTime();
	
		//cout << dt << endl;
		// Start the countdown over.  Think of laps on a stop watch.
		//clock.restart();

		// ================================ Update ================================ 
		StateMachine::getInstance()->Update(dt, num);
		num = 0;
		// ================================ Draw ================================ 
		window.clear();
		StateMachine::getInstance()->Render(window);

		window.display();
	}

}