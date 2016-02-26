#include "Fun1.h"
#include <math.h>

double Fun1::evaluate(double x){
	return 10.2-7.4*x-2.1*pow(x,2)+pow(x,3);
}

mat Fun1::evaluate(mat x){

	mat y(x.n_rows,x.n_cols);
	
	for(unsigned int i= 0;i<x.n_rows;i++){
	y(i,0) = this->evaluate(x(i,0));
	}

return y;

}

std::string Fun1::getFun(){
	return "f(x) = 10.2-7.4*x-2.1*x^2+x^3";
}

double Fun1::df(double x){
	return -7.4-4.2*x+3*x*x;
}
