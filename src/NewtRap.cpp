#include "NewtRap.h"
#include <cstdlib>
#include <fstream>
#include <cmath> 

NewtRap::NewtRap(IFun *f,double lo,double hi):
Fun(f),
acc(0.00001)
{
	x= new double[2];
	x[0] = lo;
	x[1] = hi;
	std::cout<<"\n****** ROOT FINDER -- Using "<<getMeth()<<" ******\nFinding Roots of Function \n-------\n"<<Fun->getFun()<<"\n-------"<<std::endl;
	std::cout<<"Range: "<<x[0]<<" --> "<<x[1]<<"\n-------"<<std::endl;

}

int NewtRap::numRoots(){

double step = (x[1]-x[0])/100.;
int sign[2]={0};
int count=0;
double y;


for(int i =0;i<101;i++){
	y = Fun->evaluate(x[0] + i*step);
	sign[1] = sgn(y);
	if(i==0) sign[0]=sign[1];

	if(sign[1]!=sign[0]){
			count++;
			sign[0]=sign[1];
		}
	}
return count;
}


mat NewtRap::roughRoots(){

double step = (x[1]-x[0])/100.;
int sign[2]={0};
int count=0;
double y;
double RuffX;
int nRoot = this->numRoots();
mat Ruff(nRoot,1);

for(int i =0;i<101;i++){
	RuffX = x[0] +i*step;
	y = Fun->evaluate(RuffX);
	sign[1] = sgn(y);
	if(i==0) sign[0]=sign[1];

	if(sign[1]!=sign[0]){
		
		Ruff(count,0) = RuffX; 	
		count ++;
		sign[0]=sign[1];
		}
	}
return Ruff;
}

mat NewtRap::findRoots(){

int nRoot = this->numRoots();
mat res(nRoot,1);
mat Ruff(this->roughRoots());
double d;
double converge;
	for(int i = 0;i<nRoot;i++){
		int count=0;
		x[0] = Ruff(i,0);
		converge =1;
		x[1] = x[0];
	
		while(converge > acc){ 

			count++;
			d = -(Fun->evaluate(x[1]))/(Fun->df(x[1]));
			x[1] = x[0] + d;
			converge = std::abs(x[1]-x[0]);
			x[0] = x[1];

		}//end while

		std::cout<<"Root number "<<i<<" converged after "<<count<<" iterations"<<std::endl;

		res(i,0) = x[1];
	}//end for
cout<<"\n$$$ RESULTS $$$"<<endl;
return res;
}

std::string NewtRap::getMeth(){
	return "Newton-Raphson";
}
