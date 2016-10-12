#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

#define n 100000
#define eta 1e-2
#define ep 1e-5

int main() {
	double x[n], y[n];
	ofstream myfile;
	myfile.open("0");
	for(int i=0;i<n;i++){
		x[i] = ((double) rand() / (RAND_MAX));
		y[i] = sqrt(1-(x[i]*x[i]));
		myfile<<x[i]<<" "<<y[i]<<endl;
	}
	myfile.close();
	double del_x, del_y, z = sqrt((x[0]*x[0])+(y[0]*y[0]));
	int i=1;
	while(z>ep){
		string s = to_string(i);
		myfile.open(s.c_str());
		for(int i=0;i<n;i++){
			x[i] = x[i]-(2*eta*x[i]);
			y[i] = y[i]-(2*eta*y[i]);
			myfile<<x[i]<<" "<<y[i]<<endl;
		}
		myfile.close();
		z = sqrt((x[0]*x[0])+(y[0]*y[0]));
		cout<<i<<" "<<z<<endl;
		i++;
	}
	return 0;
}
