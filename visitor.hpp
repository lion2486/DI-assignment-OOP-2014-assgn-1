#ifndef VISITOR_HPP_
#define VISITOR_HPP_
#include <iostream>


class visitor{
private:
	int id;
	int targetFloor;
	int targetOffice;
public:
	visitor(int ID, int floor, int office)
	:id(ID), targetFloor(floor), targetOffice(office){

	}

	inline int getTargetFloor(){ return this->targetFloor; }
	inline int getId(){ return this->id; }
	inline int getTargetOffice(){ return this->targetOffice; }

	/**
	 * set work as done for the visitor
	 */
	inline void setWorkDone(){ this->targetFloor = 0; }
	inline void exit(){
		std::cout << "I cannot believe I finished!" << std::endl;
	}
};

#endif /* VISITOR_HPP_ */
