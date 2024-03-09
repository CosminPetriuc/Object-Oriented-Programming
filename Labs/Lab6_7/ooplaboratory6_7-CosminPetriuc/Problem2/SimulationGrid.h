#pragma once
#define MAX_ROWS 100
#define MAX_COLS 100

#include <string>
#include <vector>
// forward class declaration for Entity
class Entity;

class SimulationGrid
{
	friend class Entity;
public:

	SimulationGrid();
	SimulationGrid(int r, int c);
	SimulationGrid(std::string path);
	SimulationGrid(const SimulationGrid& other);

	~SimulationGrid();

	int get_rows();
	int get_cols();

	Entity* get_entity(int row, int column);
	Entity* createEntity(std::string s) const;

	void set_entity(int row, int column, Entity* entity);

	SimulationGrid& operator=(const SimulationGrid& other);
private:
	int rows;
	int cols;
	std::vector<Entity*> m_entities;
	Entity* grid[MAX_ROWS][MAX_COLS];
};

class Simulation {
private:
	int rows;
	int cols;
	int numCycles;
	SimulationGrid even;
	SimulationGrid odd;

	void promptForGrid(SimulationGrid& g);

public:
	Simulation();

	void run();

};

