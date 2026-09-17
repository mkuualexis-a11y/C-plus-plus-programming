#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float interest,principal,rate,time;
	
	cout<<"Enter the principal amount(Ksh): ";
	cin>>principal;
	
	cout<<"Enter the rate: ";
	cin>>rate;
	
	cout<<"Enter the time in years: ";
	cin>>time;
	
	cout<<"The interst gained is: ";
	cout<< (interest = principal * rate / 100 * time)<<" Ksh";
	
	return 0;
}