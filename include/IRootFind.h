#ifndef IROOTFIND_H
#define IROOTFIND_H

#include "armadillo"
#include "IFun.h"

using namespace arma;

class IRootFind{
	public:
	virtual mat findRoots()=0;	
	virtual int numRoots()=0;
	virtual std::string getMeth()=0;
	
	//Universal sgn function
	int sgn(double y){
		if (y > 0) return 1;
		if (y < 0) return -1;
		return 0;
		}

};
#endif
