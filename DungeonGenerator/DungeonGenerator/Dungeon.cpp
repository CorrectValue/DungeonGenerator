#include "Dungeon.h"

Dungeon::Dungeon()
{
	//default constructor
	mapImg.loadFromFile(tileset);

	mapTex.loadFromImage(mapImg);

	mapSpr.setTexture(mapTex);
}

void Dungeon::generateBSP()
{
	//map generation using BSP trees approach

}

void Dungeon::generateTunnels()
{
	//map generation using tunnelling approach

}

void Dungeon::generateCellular()
{
	//map generation using cellular automata

}

void Dungeon::generateOwn()
{
	//map generation using own simple method

}