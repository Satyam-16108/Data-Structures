#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

double infixToPrefix(string s)
{
	reverse(s.begin(),s.end());
	stack<char> st;
	string result;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		
		// If the scanned character is an operand,
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;
		// If the scanned character is an ‘(‘, push it to the stack.
		else if (c == ')')
			st.push(c);
		// If the scanned character is an ‘)’, pop until an ‘(‘ is encountered.
		else if (c == '(') {
			while (!st.empty() && st.top() != ')') {
				result += st.top();
				st.pop();
			}
			if(!st.empty()){
				st.pop();
			}		
		}

		// If an operator is scanned
		else {
			while (!st.empty() && prec(s[i]) <= prec(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	// Pop all the remaining elements from the stack
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}
	reverse(result.begin(), result.end());
	cout << result << endl;
}

int main()
{
	string exp;									
	cout << "\nEnter The Infix Expression  : ";
	getline(cin, exp);
	cout << "\n\t\tResult : " << infixToPrefix(exp) << endl;
	return 0;
}
// x+y*z/w+u
// +x+*y/zwu
