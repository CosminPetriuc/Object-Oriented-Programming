#include "Entity.h"
#include "EntityType.h"
#include <algorithm> // for std::fill
#include <sstream>
#include <iostream>
#include <iomanip>

//Entity//

Entity::Entity() : row{ 0 }, column{ 0 }
{

}

Entity::Entity(int r, int c) {
	this->row = r;
	this->column = c;
}

int Entity::get_row() {
	return this->row;
}

int Entity::get_column() {
	return this->column;
}

void Entity::set_row(int r) {
	row = r;
}

void Entity::set_column(int c) {
	column = c;
}

void Entity::demographics(unsigned int population[], const SimulationGrid& g)
{
	// set the population array to 0; we have 4 types of elements : Empty, Fox, Gopher, Plant
	std::fill(population, population + 4, 0);

	// offsets for the neighbors' coordinates
	int dx[]{ 0, 0, 1, 1, 1, -1, -1, -1 };
	int dy[]{ 1, -1, -1, 0, 1,  -1, 0, 1 };

	// row : row+1, row-1
	// col: col+0, col+0
	unsigned int numNeigh{ sizeof(dy) / sizeof(dy[0]) };

	for (unsigned int i{ 0 }; i < numNeigh; ++i)
	{
		int r{ row + dy[i] };
		int c{ column + dx[i] };

		//checks thet r and c are inside bounderies
		for (int i = 0; i < numNeigh; ++i)
		{
			int r{ row + dy[i] };
			int c{ column + dx[i] };
			// check that r and c are within bounds
			if (r >= 0 && r < g.rows && c >= 0 && c < g.cols)
			{
				EntityType et = g.grid[r][c]->what();
				// convert the enum class to int, you can use to_underlying
				population[to_underlying(et)]++;
			}
		}

	}
}

//Empty//

Empty::Empty() {
	row = 0;
	column = 0;
}

EntityType Empty::what() {
	return EntityType::EMPTY;
}

Entity* Empty::next(const SimulationGrid& g) {
	unsigned int population[4];
	demographics(population, g);
	
	if (population[3] >= 1) {
		return g.createEntity("P");

	}
	else if (population[2] > 1) {
		return g.createEntity("G");
	}
	else if (population[1] > 1) {
		return g.createEntity("F");
	}
	else {
		return g.createEntity("E");
	}
}


std::ostream& operator<<(std::ostream& os, const Empty& obj) {
	os << obj.toString();
	return os;
}

//Plant//

Plant::Plant() {
	row = 0;
	column = 0;
}

EntityType Plant::what() {
	return EntityType::PLANT;
}

Entity* Plant::next(const SimulationGrid& g) {
	unsigned int population[4];
	demographics(population, g);

	if (population[2] == 2 * population[3]) {
		return g.createEntity("E");
	}
	else if (population[2] >= 3) {
		return g.createEntity("G");
	}
	else {
		return g.createEntity("P");
	}
}



std::ostream& operator<<(std::ostream& os, const Plant& plant) {
	os << plant.toString();
	return os;
}


//Animal//

int Animal::get_age() const {
	return age;
}

void Animal::set_age(int a) {
	age = a;
}


//Fox//

Fox::Fox() {
	row = 0;
	column = 0;
}

EntityType Fox::what() {
	return EntityType::FOX;
}

Entity* Fox::next(const SimulationGrid& g) {
	unsigned int population[4];
	demographics(population, g);

	if (age >= 5 || population[2] == 0) {
		return g.createEntity("E");
	}
	else {
		return g.createEntity("F");
	}
}



std::ostream& operator<<(std::ostream& os, const Fox& fox) {
	os << fox.toString();
	return os;
}


//Gopher//

Gopher::Gopher() {
	row = 0;
	column = 0;
}

EntityType Gopher::what() {
	return EntityType::GOPHER;
}

Entity* Gopher::next(const SimulationGrid& g) {
	unsigned int population[4];
	demographics(population, g);
	
	if (age == 4 || population[3] == 0) {
		return g.createEntity("E");
	}
	else if (population[1] >= population[2]) {
		return g.createEntity("F");
	}
	else {
		return g.createEntity("G");
	}
}


std::ostream& operator<<(std::ostream& os, const Gopher& gopher) {
	os << gopher.toString();
	return os;
}