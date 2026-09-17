#include <iostream>
using namespace std;
int main()
{
  float base; 	
  int height;	
	
  cout<<"Enter the base in meters: ";
  cin>>base;
  
  cout<<"Enter the height in meters: ";
  cin>>height;
  
  cout<<"The area is: ";
  cout<< (0.5 * base * height) <<" square meters";
  	
	return 0;
}