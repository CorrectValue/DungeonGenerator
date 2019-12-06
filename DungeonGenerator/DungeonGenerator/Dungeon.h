#ifndef DGN
#define DGN
#include <SFML/Graphics.hpp>


using namespace sf;

const int width = 64;
const int height = 48;

class Dungeon
{
	//main dungeon class
	String tileset;
	Image mapImg;//изображение карты

	Texture mapTex;//текстура карты

	Sprite mapSpr;

	String TileMap[height][width];

	Dungeon();
	void generateBSP();
	void generateTunnels();
	void generateCellular();
	void generateOwn();
};

#endif