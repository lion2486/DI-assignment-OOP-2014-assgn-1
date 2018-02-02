#include <iostream>
#include "office.hpp"



office::office(int i, int N_office)
:index(i), maxCapacity(N_office){

	this->visitors = new List();

	std::cout << "Office number " << i << " has been created" << std::endl;
}

office::~office(){
	this->visitors->Remove_All_Items();

	delete this->visitors;

	std::cout << "End of the work!" << std::endl;
}

bool office::enter(visitor * v){

	if(this->visitors->Get_List_Size() < this->maxCapacity){
		this->visitors->Add_List_Item_at_End(v);
		std::cout << "Entering office number " << this->index << " " <<  v->getId() << std::endl;

		return true;
	}else{
		std::cout << "Please, wait outside for entrance in office number " << this->index << " " << v->getId() << std::endl;

		return false;
	}
}

visitor * office::exit(){
	visitor * v;

	if(this->visitors->Get_List_Size() == 0)
		return NULL;

	v = this->visitors->Get_List_First();
	this->visitors->Remove_List_Item(0);

	return v;
}
