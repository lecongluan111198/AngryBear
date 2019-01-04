#include <math.h>
#include <cstdlib>
#include <vector>
#include <ctime> 
#include <iostream>
#include "Model/GameManager.h"
#include "Model/ResourceManager.h"
#include "SFML/Graphics.hpp"
#include "Define/Define.h"
using namespace sf;
using namespace std;



int main(int argc, char** argv)
{
	srand((unsigned int)time(NULL));
	
	RenderWindow window(VideoMode(WINDOWS_W, WINDOWS_H), "Spaceship Game!", Style::Default);
	window.setFramerateLimit(FPS_LIMIT);

	// ============================ Init ============================


	//test
	ResourceManager::getInstance()->Init();
	ResourceManager::getInstance()->loadData();
	//


	GameManager::getInstance()->Init();

	Clock clock;
	Time elapsed;
	int num = 0;
	while (window.isOpen())
	{
		Event event;
		// A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
		float dt = clock.getElapsedTime().asMicroseconds() * 1.0f / 1000000;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Left))
				num = 71;
			if (Keyboard::isKeyPressed(Keyboard::Right))
				num = 72;
			if (Keyboard::isKeyPressed(Keyboard::Up))
				num = 73;
			if (Keyboard::isKeyPressed(Keyboard::Down))
				num = 74;
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				// transform the mouse position from window coordinates to world coordinates
				sf::Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
				GameManager::getInstance()->UpdateColor(dt, mouse);
			}
		}

		elapsed = clock.getElapsedTime();
	
		
		//std::cout << "dt: " << dt << std::endl;
		// Start the countdown over.  Think of laps on a stop watch.
		clock.restart();

		// ================================ Update ================================ 
		GameManager::getInstance()->Update(dt,num);
		num = 0;
		// ================================ Draw ================================ 
		window.clear();
		GameManager::getInstance()->Render(window);

		window.display();
	}

}