#include <math.h>
#include <cstdlib>
#include <vector>
#include <ctime> 
#include <iostream>
#include "Model/GameManager.h"
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
	GameManager::getInstance()->Init();

	Clock clock;
	Time elapsed;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		elapsed = clock.getElapsedTime();
		// A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
		float dt = clock.getElapsedTime().asMicroseconds() * 1.0f / 1000000;
		//std::cout << "dt: " << dt << std::endl;
		// Start the countdown over.  Think of laps on a stop watch.
		clock.restart();

		// ================================ Update ================================ 
		GameManager::getInstance()->Update(dt);

		// ================================ Draw ================================ 
		window.clear();
		GameManager::getInstance()->Render(window);

		window.display();
	}

}