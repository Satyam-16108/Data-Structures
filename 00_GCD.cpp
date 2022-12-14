
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	int result = min(a, b);
	while (result > 0) {
		if (a % result == 0 && b % result == 0) {
			break;
		}
		result--;
	}
	return result;
}

int main()
{
	int a , b;
	char ch;
	do{
	cout<<"Enter a : ";
	cin>>a;
	cout<<"Enter b : ";
	cin>>b;
	cout << "GCD of " << a << " and " << b << " is "<< gcd(a, b);
	cout<<"\nDo you want to enter more y/n :";
	cin>>ch;
	}while(ch='y');
	return 0;
}


