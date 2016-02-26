#ifndef FUN1_H
#define FUN1_H

#include "IFun.h"

class Fun1 : public IFun{
	public:
		double evaluate(double x);
		mat evaluate(mat x);
		std::string getFun();
		double df(double);
};
#endif
