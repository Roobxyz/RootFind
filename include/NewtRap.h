#ifndef NEWTRAP_H
#define NEWTRAP_H

#include "IRootFind.h"

class NewtRap : public IRootFind{
	public:
	NewtRap(IFun *f,double lo,double hi);
	mat findRoots();
	int numRoots();

	private:
	IFun *Fun;
	double *x;
	double acc;
	std::string getMeth();
        mat roughRoots(); //Specific NR
};

#endif
