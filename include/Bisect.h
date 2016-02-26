#ifndef BISECT_H
#define BISECT_H

#include "IRootFind.h"

class Bisect : public IRootFind{
	public:
	Bisect(IFun *f,double lo,double hi);
	mat findRoots();
        int numRoots();


	private:
	IFun *Fun;
	double *x;
	double acc;
	std::string getMeth();
};
#endif
