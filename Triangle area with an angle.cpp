#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  float a; 	
  float b;	
  float c;
	
  cout<<"Enter the length a in meters: ";
  cin>>a;
  
  cout<<"Enter the length b in meters: ";
  cin>>b;
  
  cout<<"Enter the angle c: ";
  cin>>c;
  
  cout<<"The area is: ";
  cout<< (0.5 * a * b * sin(c * M_PI / 180)) <<" square meters";
  	
	return 0;
}