#include "Bisect.h"
#include <cstdlib>
#include <fstream>
#include <cmath> 

Bisect::Bisect(IFun *f,double lo,double hi):
Fun(f),
acc(0.00001)
{
	x= new double[2];
	x[0] = lo;
	x[1] = hi;
	std::cout<<"\n****** ROOT FINDER -- Using "<<this->getMeth()<<" ******\nFinding Roots of Function \n-------\n"<<Fun->getFun()<<"\n-------"<<std::endl;
	std::cout<<"Range: "<<x[0]<<" --> "<<x[1]<<"\n-------"<<std::endl;

}

int Bisect::numRoots(){

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

mat Bisect::findRoots(){
	
double lo = x[0]; //lo < hi **important
double hi = x[0] +0.5;
double mid = lo + (hi-lo)/2.;

double y[3]={0};

int nRoot = this->numRoots();
mat res(nRoot,1);

	for(int i = 0;i<nRoot;i++){
		int count=0;
		while(std::abs (hi-lo) > acc){

			count++;

			y[0] = Fun->evaluate(lo);//lo range
			y[1] = Fun->evaluate(hi);//hi range		
			
				while(sgn(y[0])==sgn(y[1])){
				hi =hi +0.5;
				mid = lo + std::abs (hi-lo) /2.;
				y[0] = Fun->evaluate(lo);//lo range
				y[1] = Fun->evaluate(hi);//hi range		
				}//end while

			y[2] = Fun->evaluate(mid); //mid range 
			
			//ensures lo and hi are either side of the root
			if(sgn(y[1])!=sgn(y[0])){
			
				if(sgn(y[2])==sgn(y[1])){
						hi=mid;
				} else if(sgn(y[2])==sgn(y[0])){
					lo=mid;
				} //end if

			mid =std::abs (hi-lo) /2. +lo;
		
			}//end if
		
		
		}//end while

		std::cout<<"Root number "<<i<<" converged after "<<count<<" iterations"<<std::endl;
		
		res(i,0) = mid;
		lo= mid +0.01;
		hi =lo + 0.5;
		mid =std::abs( hi-lo) /2. +lo;
	}//end for

cout<<"\n$$$ RESULTS $$$"<<endl;
return res;
}

std::string Bisect::getMeth(){
	return "Bisection";
}
