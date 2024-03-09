#include <iostream>
#include <cassert>
#include <vector>
#include "Entity.h"

class EntityTest {
public:
	static void runTests() {
		testGetRow();
		testGetColumn();
		testSetRow();
		testSetColumn();

	}
private:
	static void testGetRow() {
		Entity E( 2, 3);
		assert(E.get_row() == 2);
	}
	
	static void testGetColumn() {
		Entity E(2, 3);
		assert(E.get_column() == 3);
	}

	static void testSetRow() {
		Entity E(0, 0);
		E.set_row(2);
		assert(E.get_row() == 2);
	}

	static void testSetColumn() {
		Entity E(0, 0);
		E.set_column(3);
		assert(E.get_column() == 3);
	}
};