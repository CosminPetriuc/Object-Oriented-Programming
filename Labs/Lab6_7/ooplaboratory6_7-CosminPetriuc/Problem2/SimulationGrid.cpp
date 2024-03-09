#include "SimulationGrid.h"
#include "Entity.h"
#include <iostream>
#include <iomanip>
#include <fstream>

SimulationGrid::SimulationGrid() {
	rows = 0;
	cols = 0;

	for (int r = 0; r < MAX_ROWS; r++) {
		for (int c = 0; c < MAX_COLS; c++) {
			grid[r][c] = nullptr;
		}
	}
}

SimulationGrid::SimulationGrid(int r, int c) {
	rows = r;
	cols = c;

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			grid[r][c] = nullptr;
		}
	}
}

SimulationGrid::SimulationGrid(std::string path) {
	std::ifstream file(path, std::ios::in);

	if (!file) {
		std::cerr << "Error: The file could not be opened \"" << path << "\" for reading." << std::endl;
		return;
	}

	SimulationGrid sg;
	//file >> sg;

	file.close();

}

SimulationGrid::SimulationGrid(const SimulationGrid& other)
{
	rows = other.rows;
	cols = other.cols;

	for (int i = 0; i < other.rows; i++)
	{
		for (int j = 0; j < other.cols; j++)
		{
			grid[i][j] = other.grid[i][j];
		}
	}
}

SimulationGrid::~SimulationGrid()
{
	// delete all entities in the grid
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (grid[r][c] != nullptr)
			{
				delete grid[r][c];
				grid[r][c] = nullptr;
			}
		}
	}
}

int SimulationGrid::get_rows()
{
	return rows;
}

int SimulationGrid::get_cols()
{
	return cols;
}

Entity* SimulationGrid::get_entity(int row, int col)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols)
	{
		return grid[row][col];
	}
	else
	{
		return nullptr;
	}
}

void SimulationGrid::set_entity(int row, int col, Entity* entity)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols)
	{
		grid[row][col] = entity;
	}
}


SimulationGrid& SimulationGrid::operator=(const SimulationGrid& other)
{
	rows = other.rows;
	cols = other.cols;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			grid[i][j] = other.grid[i][j];
		}
	}

	return *this;
}

Entity* SimulationGrid::createEntity(std::string s) const
{
	if (s == "P")
	{
		return new Plant;
	}
	else if (s == "E")
	{
		new Empty();
	}
	else if (s[0] == 'F' && s.length() == 2 && isdigit(s[1]))
	{
		int age = s[1] - '0';
		return new Fox();
	}
	else if (s[0] == 'G' && s.length() == 2 && isdigit(s[1]))
	{
		int age = s[1] - '0';
		return new Gopher();
	}
	else
	{
		return nullptr;
	}
}

