#ifndef ENTRANCE_HPP_
#define ENTRANCE_HPP_
#include "visitor.hpp"
#include "List.h"

class entrance{
private:
	List * visitors;
	int maxCapacity;
public:
	entrance(int cap);

	~entrance();

	/**
	 * enters a visitor into the floor (or ground) entrance space
	 */
	bool enter(visitor * v);

	/**
	 * gets the visitor with the min priority num
	 */
	inline visitor * exit(){ return this->exit(-1); }

	/**
	 * gets the visitor with the min priority num for the target office
	 */
	visitor * exit(int office);

	inline int getCap(){	return this->visitors->Get_List_Size(); }

};

#endif /* ENTRANCE_HPP_ */
