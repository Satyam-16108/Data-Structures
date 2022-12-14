#include <bits/stdc++.h>
using namespace std;

double evalPrefix(string exp)
{
	stack<double> Stack;

	for (int j = exp.size() - 1; j >= 0; j--) {
	
		if (exp[j] == ' ')
			continue;

		if (isdigit(exp[j])) {
			double num = 0, i = j;
			while (j < exp.size() && isdigit(exp[j]))
				j--;
			j++;

			for (int k = j; k <= i; k++)
				num = num * 10 + double(exp[k] - '0');

			Stack.push(num);
			cout<< num << " Pushed Into Stack"<<endl;
		}
		else {

			double o1 = Stack.top();
			Stack.pop();
			cout<< o1 << " Popped Out Of Stack"<<endl;
			double o2 = Stack.top();
			Stack.pop();
			cout<< o2 << " Popped Out Of Stack"<<endl;

			switch (exp[j]) {
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
	cout << "\nEnter The Prefix Expression  : ";
	getline(cin, exp);
	cout << "\n\t\tResult : " << evalPrefix(exp) << endl;
	return 0;
}
//  + 9 * 12 6
//   81
