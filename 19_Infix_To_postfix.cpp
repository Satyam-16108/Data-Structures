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

double infixToPostfix(string s)
{

	stack<char> st;
	string result;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		
		// If the scanned character is an operand,
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;
		// If the scanned character is an ‘(‘, push it to the stack.
		else if (c == '(')
			st.push('(');
		// If the scanned character is an ‘)’, pop until an ‘(‘ is encountered.
		else if (c == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop();
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
	cout << result << endl;
}

int main()
{
	string exp;									
	cout << "\nEnter The Infix Expression  : ";
	getline(cin, exp);
	cout << "\n\t\tResult : " << infixToPostfix(exp) << endl;
	return 0;
}
// a+b*(c^d-e)^(f+g*h)-i
// abcd^e-fgh*+^*+i-
