#include <bits/stdc++.h>
using namespace std;

int evalPostfix(string exp)
{
	stack<double> Stack;

	for (int i = 0; exp[i]; ++i)
	{
		if(exp[i] == ' ')
			continue;

		else if (isdigit(exp[i]))
		{
			int num=0;
			while(isdigit(exp[i]))
			{
			   num = num * 10 + (int)(exp[i] - '0');
			   i++;
			}
			i--;
			Stack.push(num);
			cout<< num << " Pushed Into Stack"<<endl;
		}
		
		else
		{   double o2 = Stack.top();
			Stack.pop();
			cout<< o2 << " Popped Out Of Stack"<<endl;
			double o1 = Stack.top();
			Stack.pop();
			cout<< o1 << " Popped Out Of Stack"<<endl;

			switch (exp[i]) {
			case '+':
				Stack.push(o1 + o2);
				cout<< (o1 + o2) << " Pushed Into Stack"<<endl;
				break;
			case '-':
				Stack.push(o1 - o2);
				cout<< (o1 - o2) << " Pushed Into Stack"<<endl;
				break;
			case '*':
				Stack.push(o1 * o2);
				cout<< (o1 * o2) << " Pushed Into Stack"<<endl;
				break;
			case '/':
				Stack.push(o1 / o2);
				cout<< (o1 / o2) << " Pushed Into Stack"<<endl;
				break;
			case '^':
				Stack.push(pow(o1,o2));
				cout<< (pow(o1,o2)) << " Pushed Into Stack"<<endl;
				break;
		}
	}
  }
  	return Stack.top();
}

int main()
{
	string exp;									
	cout << "\nEnter The Postfix Expression  : ";
	getline(cin, exp);
	cout << "\n\t\tResult : " << evalPostfix(exp) << endl;
	return 0;
}
//  100 200 + 2 / 5 * 7 +
//  757
