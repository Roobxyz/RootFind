#include "Fun1.h"
#include "Fun2.h"
#include "Bisect.h"
#include "NewtRap.h"
#include <cstdlib>
#include <fstream>

int main ()
{
	//set the stream output precision
	cout.precision(5);
	cout.setf(ios::fixed);

        //Function Interface pointer to f
	IFun *p = new Fun1;
	
	//RootFind Interface point to a new Bisect object -- Bisect takes a function pointer argument 
	IRootFind *RF = new Bisect(p,-5.,5.);
	mat BRes = RF->findRoots(); //finds roots and displays
	BRes.raw_print(cout, "");
	
	//RootFind interface pointing to new NewtRap obbject -- find and display roots
	RF = new NewtRap(p,-5.,5);
	mat NRRes = RF->findRoots();
	NRRes.raw_print(cout, "");
	
	//std::cout<<"\nActual roots: -2.497709366, 1.202957284, 3.394752082"<<std::endl;

	//function Interface now points to g and process is repeated after pointers point to new RootFind objects
	p = new Fun2;

	RF = new Bisect(p,-5.,5.);
	BRes = RF->findRoots();
	BRes.raw_print(cout, "");

	RF = new NewtRap(p,-5.,5);
	NRRes = RF->findRoots();
	NRRes.raw_print(cout, "");

	//std::cout<<"\nActual root: 0.6931471806"<<std::endl;

	return 0;
}
