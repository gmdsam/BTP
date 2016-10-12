#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

#define n 10000			//number of points on a plane z=c
#define eta 1e-2		//rate at which bubble collapses/expands
#define ep 1e-5			//stopping condition for gradient descent
#define c 1			//initial plane z=c on which we will generate random x and y

int main() {
	double x[n], y[n];
	ofstream myfile;
	myfile.open("0");
	
	//generating n random points on plane z=c on which gradient
	//descent will be applied and storing them in file named '0'
	for(int i=0;i<n;i++){
		x[i] = ((double) rand() / (RAND_MAX));
		y[i] = sqrt(c-(x[i]*x[i]));
		myfile<<x[i]<<" "<<y[i]<<endl;
	}
	myfile.close();
	
	double del_x, del_y;
	double z = c;		//initial plane on which n points are randomly generated
	int i=1;
	
	//loop until z plane is above z=ep
	while(z>ep){
		
		//generating filenames to store all values of x and y
		//that are present on a single plane
		string s = to_string(i);
		myfile.open(s.c_str());
		
		//computing new values of x and y using gradient descent
		//and storing them in new file named 'i' (where i = 1, 2, ..)
		for(int i=0;i<n;i++){
			x[i] = x[i]-(2*eta*x[i]);
			y[i] = y[i]-(2*eta*y[i]);
			myfile<<x[i]<<" "<<y[i]<<endl;
		}
		myfile.close();
		
		//computing value of z from new values of x and y
		z = sqrt((x[0]*x[0])+(y[0]*y[0]));
		//cout<<i<<" "<<z<<endl;
		i++;
	}
	return 0;
}
