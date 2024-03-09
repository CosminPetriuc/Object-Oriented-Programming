#pragma once
#include "EntityType.h"
#include "SimulationGrid.h"
#include <string>
class Entity
{
public:
	// TODO make pure abstract method

	Entity();
	Entity(int r, int c);

	int get_row();
	int get_column();

	void set_row(int r);
	void set_column(int c);

	virtual std::string toString() const = 0;
	
	virtual Entity* next(const SimulationGrid& g) = 0;

	virtual EntityType what() = 0;

	void demographics(unsigned int population[], const SimulationGrid& g);
	static void runTests();
protected:
	 int row;
	 int column;

};

class Empty : public Entity {
public:

	Empty();
	Empty(int row, int column);

	EntityType what() override;

	std::string toString() const override {
		return "E";
	}
	Entity* next(const SimulationGrid& g) override;

	friend std::ostream& operator<<(std::ostream& os, const Entity& obj);
};

class Animal : public Entity {
protected:
	int age;

public:

	int get_age() const;
	void set_age(int a);
};

class Fox : public Animal {
public:

	Fox();
	Fox(int row, int column);

	EntityType what() override;

	std::string toString() const override {
		return "F";
	}
	Entity* next(const SimulationGrid& g) override;

	friend std::ostream& operator<<(std::ostream& os, const Fox& fox);
};

class Gopher : public Animal {
public:

	Gopher();
	Gopher(int row, int column);

	EntityType what() override;

	std::string toString() const override {
		return "G";
	}
	Entity* next(const SimulationGrid& g) override;

	friend std::ostream& operator<<(std::ostream& os, const Gopher& gopher);
};

class Plant : public Entity {
public:

	Plant();
	Plant(int row, int column);

	EntityType what() override;

	std::string toString() const override {
		return "P";
	}
	Entity* next(const SimulationGrid& g) override;

	friend std::ostream& operator<<(std::ostream& os, const Plant& plant);
};

