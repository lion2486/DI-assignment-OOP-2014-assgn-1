#ifndef OFFICE_HPP_
#define OFFICE_HPP_
#include "List.h"

class office{
private:
	List * visitors;
	int index;
	int maxCapacity;
public:

	office(int i, int N_office);
	~office();

	inline int getCapacity()	{ return this->visitors->Get_List_Size(); }
	inline int getMaxCapacity()	{ return this->maxCapacity; }

	/**
	 * enters a visitor into the office
	 */
	bool enter(visitor * v);

	/**
	 * get an visitor from the office to get off the building
	 */
	visitor * exit();
};

#endif /* OFFICE_HPP_ */
