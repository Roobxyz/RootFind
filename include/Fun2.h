
#ifndef FUN2_H
#define FUN2_H

#include "IFun.h"

class Fun2 : public IFun{
	public:
		double evaluate(double x);
		mat evaluate(mat x);
		std::string getFun();
		double df(double);
};
#endif
