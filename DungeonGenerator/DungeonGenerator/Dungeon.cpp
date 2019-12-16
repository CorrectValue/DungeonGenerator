#include "Dungeon.h"

Dungeon::Dungeon()
{
	//default constructor
	tileset = "0.png";
	//loading images from file
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

void Dungeon::generateCellular() //needs refinery
{
	//map generation using cellular automata
	//step 0. initialize a grid of cells
	float aliveProbability = 0.3f; //probability for a cell to be generated alive
	int birthLimit = 3, deathLimit = 2;
	float rnd;
	for (int i = 1; i < height-1; i++)
	{
		for (int j = 1; j < width-1; j++)
		{
			rnd = rand() % 100;
			rnd /= 100;
			if (rnd < aliveProbability)
			{
				TileMap[i][j] = '#';
			}
			else
				TileMap[i][j] = ' ';
		}
	}
	//pre-generation completed
	//kickstart iterative process
	String Copy[height][width];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			Copy[i][j] = '#';
		}
	}
	//step 1: recalculate state of every cell and write to a different map
	for (int gen = 0; gen < 5; gen++)
	{
		for (int i = 1; i < height - 1; i++)
		{
			for (int j = 1; j < width - 1; j++)
			{
				//step 2.1: check alive neighbors
				int aliveN = checkAliveNeighbors(i, j);
				//step 2.2: decide if the cell is alive or dead
				if (TileMap[i][j] == '#')
				{
					//the cell is alive
					if (aliveN < deathLimit)
					{
						//cell dies
						Copy[i][j] = ' ';
					}
					else
						//remains alive
						Copy[i][j] = '#';
				}
				else
				{
					//the cell is dead
					if (aliveN > birthLimit)
					{
						//cell comes to life
						Copy[i][j] = '#';
					}
					else
						//remains dead
						Copy[i][j] = ' ';
				}
			}
		}
		//step 2: duplicate map
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				TileMap[i][j] = Copy[i][j];
			}
		}
	}
}

void Dungeon::generateOwn()
{
	//map generation using own simple method
	//step 0. initialize a list of all cells of the dungeon
	std::vector<cell> cells;
	for (int i = 1; i < height - 1; i++)
	{
		for (int j = 1; j < width - 1; j++)
		{
			cells.push_back({ i, j });
		}
	}
	//step 1. generate a single cell within field
	TileMap[rand() % (height - 1) + 1][rand() % (width - 1) + 1] = ' ';
	//step 2. 

}

void Dungeon::draw(RenderWindow& window)
{
	//visualization method
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//код обработки строки карты
			if (TileMap[i][j] == ' ')
			{
				mapSpr.setTextureRect(IntRect(0, 0, 16, 16));
			}
			else if (TileMap[i][j] == '#')
			{
				mapSpr.setTextureRect(IntRect(16, 0, 16, 16));
			}
			mapSpr.setPosition(j * 16, i * 16);
			window.draw(mapSpr);
		}
	}
}

void Dungeon::prepareMap()
{
	//method that prepares map for future generation
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			TileMap[i][j] = '#';
		}
	}
}

int Dungeon::checkAliveNeighbors(int x, int y)
{
	//returns number of alive neighbors for a cell with given x and y
	int aliveQtr = 0; //num of alive neighbors
	int iter = 0;
	int dx = -1, dy = -1;
	for (dx = -1; dx <= 1; dx++)
	{
		for (dy = -1; dy <= 1; dy++)
		{
			if (dx || dy)
			{
				iter++;
				if (TileMap[x + dx][y + dy] == '#')
					aliveQtr++;
			}
		}
	}

	return aliveQtr;
}