#ifndef IFUN_H
#define IFUN_H

#include "armadillo"
#include <cstdlib>
#include <string>

using namespace arma;

class IFun{
public:	
	virtual double evaluate(double)=0;
	virtual mat evaluate(mat)=0;
	virtual std::string getFun()=0; 
	virtual double df(double) =0;
};
#endif
