#include <iostream>
#include "floor.hpp"

floor::floor(int cap, int f, int N_office)
:maxCapacity(cap), floor_num(f){

	for(int i=0; i<MAX_OFFICES; i++)
		this->offices[i] = new office(i, N_office);

	this->ent = new entrance(cap);

	std::cout << "A Floor has been created with number " << f << std::endl;
}

floor::~floor(){

	for(int i=0; i<MAX_OFFICES; i++)
			delete this->offices[i];

	delete this->ent;

	std::cout << "End of service!" << std::endl;
}

bool floor::enter(visitor * v){
	if(this->ent->enter(v)){
		std::cout << "Entering floor number " << this->floor_num << " " <<  v->getId() << std::endl;

		//try to enter a visitor int office
		for(int i=0; i<MAX_OFFICES && this->ent->getCap(); i++){
			if( this->offices[i]->getMaxCapacity() > this->offices[i]->getCapacity()){
				visitor * v = this->ent->exit();
				this->offices[i]->enter(v);
			}
		}

		return true;
	}else{
		std::cout << "Sorry, floor number " << this->floor_num << " is full " << v->getId() << std::endl;

		return false;
	}
}

visitor * floor::exit(){
	visitor * v;

	//pops out a visitor from an office
	for(int i=0; i<MAX_OFFICES; i++){
		v = this->offices[i]->exit();
		if(v != NULL)
			break;
	}

	//try to enter a visitor int office
	for(int i=0; i<MAX_OFFICES && this->ent->getCap(); i++){
		if( this->offices[i]->getMaxCapacity() > this->offices[i]->getCapacity()){
			visitor * v = this->ent->exit();
			this->offices[i]->enter(v);
		}
	}


	return v;
}
