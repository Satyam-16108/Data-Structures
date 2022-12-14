#include <bits/stdc++.h>
using namespace std;

unsigned int factorial(unsigned int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * factorial(n - 1);
}

int main()
{
	int num;
	char ch;
	do{
	cout<<"ENTER A NUMBER : ";
	cin>>num;
	cout << "Factorial of " << num << " is " << factorial(num) << endl;
	cout<<"DO YOU WANT TO ENTER MORE y -> YES  n -> NO ";
	cin>>ch;
	}while(ch=='y');
	return 0;
}