#include <SFML/Graphics.hpp>
#include "Dungeon.h"

using namespace sf;
void main()
{
	View view(FloatRect(0, 0, 1600, 1600));
	RenderWindow window(sf::VideoMode(1024, 1024), "GETTING STARTED");

	//get user opinion on desirable generation algorithm

	//generate dungeon using desirable algorithm
	Dungeon dng;
	dng.prepareMap();
	dng.generateTunnels();
	//dng.generateCellular();
	//visualize generated dungeon
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.setView(view);
		//window.clear();*/

		dng.draw(window);
		window.display();
	}
}