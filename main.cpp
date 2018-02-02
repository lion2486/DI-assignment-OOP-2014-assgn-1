#include <iostream>
#include <cstdlib>
#include "List.h"
#include "building.hpp"
#include "visitor.hpp"

int main(int argc, char * argv[]) {
	int N, N_floor, N_ground, N_office, N_lift, K, L;
	building * b;
	List visitors;
	int visitorID = 0;

	srand(time(NULL));

	if(argc < 7){
		std::cerr << "Call with exact 7 arguments, N, Nf, Ng, No, Nl, K, L" << std::endl;

		return EXIT_FAILURE;
	}

	//add arguments to variables
	N 			= atoi(argv[1]);
	N_floor 	= atoi(argv[2]);
	N_ground 	= atoi(argv[3]);
	N_office 	= atoi(argv[4]);
	N_lift		= atoi(argv[5]);
	K			= atoi(argv[6]);
	L			= atoi(argv[7]);

	//validation tests
	if(N_floor >= N/3 || N_ground >= N/2 || N_office >= N_floor || N_lift <= N_office ){
		std::cerr << "Data given are invalid, exiting..." << std::endl;

		return EXIT_FAILURE;
	}

	//create the building
	b = new building(N, N_floor, N_lift, N_office, N_ground);

	//create K visitors
	for(int i=0; i<K; i++){
		visitor * v = new visitor(++visitorID, rand() % 4 + 1, rand() % 10);
		b->enter(v);
	}

	for(int i=0; i<L; i++){
		b->operate();
	}

	//destroy the building
	delete b;

	return EXIT_SUCCESS;
}
