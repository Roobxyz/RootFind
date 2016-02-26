
#include "Fun2.h"
#include <math.h>

double Fun2::evaluate(double x){
	return exp(x)-2;
}

mat Fun2::evaluate(mat x){

	mat y(x.n_rows,x.n_cols);
	
	for(unsigned int i= 0;i<x.n_rows;i++){
	y(i,0) = this->evaluate(x(i,0));
	}

return y;

}

std::string Fun2::getFun(){
	return "g(x) = exp(x) - 2";
}

double Fun2::df(double x){
	return exp(x);
}
