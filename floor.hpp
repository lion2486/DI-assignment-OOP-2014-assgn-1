#ifndef FLOOR_HPP_
#define FLOOR_HPP_
#define MAX_OFFICES 10
#include "List.h"
#include "visitor.hpp"
#include "office.hpp"
#include "entrance.hpp"

class floor{
private:
	int maxCapacity;
	int floor_num;
	office * offices[MAX_OFFICES];
	entrance * ent;
public:
	floor(int cap, int f, int N_office);
	~floor();

	inline int getCapacity()	{ return this->ent->getCap(); }
	inline int getMaxCapacity()	{ return this->maxCapacity; }

	/**
	 * the method to enter a visitor into a floor
	 */
	bool enter(visitor * v);

	/**
	 * returns an available visitor to get off the building
	 */
	visitor * exit();
};

#endif /* FLOOR_HPP_ */
