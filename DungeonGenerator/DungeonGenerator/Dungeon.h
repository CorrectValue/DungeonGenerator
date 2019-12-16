#ifndef DGN
#define DGN
#include <SFML/Graphics.hpp>
#include "enums.h"
#include <vector>


using namespace sf;

const int width = 100;
const int height = 100;

class Dungeon
{
	//main dungeon class
	String tileset;
	Image mapImg;//изображение карты
	Texture mapTex;//текстура карты
	Sprite mapSpr;

	String TileMap[height][width]; //change to boolean
public:
	Dungeon();
	void generateBSP();
	void generateTunnels();
	void generateCellular();
	void generateOwn();
	void draw(RenderWindow& window);
	void prepareMap();
	int checkAliveNeighbors(int x, int y);
};

#endif