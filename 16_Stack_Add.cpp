#include <iostream>
#include <string>
using namespace std;

template <typename X>
class Stack
{
	struct node
	{
		X data;
		struct node *next;
	};

	struct node *top, *temp;

  public:
  	int count;
	Stack() { top = NULL; }
	~Stack() { clear(); }

	bool isempty()
	{
		return (top == NULL);
	}

	void push(X n)
	{
		temp = new node;
		temp->data = n;
		if (isempty())
		{
			temp->next = NULL;
			top = temp;
		}
		else
		{
			temp->next = top;
			top = temp;
		}
		++count;
		cout << endl << n << " pushed to the stack.";
	}

	X pop()
	{
		if (isempty())
		{
			cout << "\nStack is empty!" << endl;
			return 0;
		}
		else
		{
			X n = top->data;
			if (top->next == NULL)
			{
				delete top;
				top = NULL;
			}
			else
			{
				temp = top;
				top = top->next;
				delete temp;
			}
			--count;
			return n;
		}
	}

	X topEl()
	{
		if(isempty())
		{
			cout << "\nStack is empty!" << endl;
			return 0;
		}
		else return top->data;
	}

	void clear()
	{
		cout << "\nClearing the stack...";
		while (!isempty())
			pop();
		cout << " Done" << endl;
	}

	void display()
	{
		if (isempty())
			cout << "\nStack is empty!" << endl;
		else
		{
			cout << "\nStack<" << count << "> : top--> ";
			temp = top;
			while (temp != NULL)
			{
				if (temp == top)
					cout << temp->data;
				else
					cout << "-> " << temp->data;
				temp = temp->next;
			}
			cout << endl;
		}
	}
};

void tostack(string &n, Stack<int> &s)
{
	for (int i = 0; i < n.length(); ++i)
	{
		s.push((int)(n[i] - 48));
	}
}

void add(Stack<int> &s1, Stack<int> &s2, Stack<int> &sum)
{
	int n1, n2, carry = 0;
	int itr = (s2.count > s1.count) ? s2.count : s1.count;
	for (int i = 0; i < itr; i++)
	{
		n1 = s1.isempty() ? 0 : s1.pop();
		n2 = s2.isempty() ? 0 : s2.pop();

		sum.push((n1 + n2 + carry) % 10);
		carry = (n1 + n2 + carry) / 10;
	}
	if (carry > 0)
		sum.push(carry);
}

int main()
{
	string n;
	Stack<int> s1, s2, s3;
	cout << "\nEnter 1st number: ";
	cin >> n;
	tostack(n, s1);
	cout << "Enter 2nd number: ";
	cin >> n;
	tostack(n, s2);
	cout << "\n\tSum\t: ";
	add(s1, s2, s3);
	s3.display();
	cout << endl;
}
