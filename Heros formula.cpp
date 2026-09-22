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
  
  cout<<"Enter the length c in meters: ";
  cin>>c;
  
   float s = ((a + b + c) * 0.5f);
  
  cout<<"The area is: ";
  cout<< sqrt(s*(s-a)*(s-b)*(s-c) ) <<" square meters";
  	
	return 0;
}