#include <SFML/Graphics.hpp>

using namespace sf;
void main()
{
	RenderWindow window(sf::VideoMode(1024, 768), "GETTING STARTED");

	//get user opinion on desirable generation algorithm

	//generate dungeon using desirable algorithm

	//visualize generated dungeon
	while (window.isOpen())
	{
		window.display();
	}
}