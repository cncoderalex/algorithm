#include<stack>
#include<iostream>

using namespace std;

template<typename T>
void PrintStack(stack<T> &s)
{
	while (!s.empty())
	{
		T t1 = s.top();
		s.pop();
		cout << t1 << " ";
	}
	cout << endl;
}

template<typename T>
T GetAndRemoveLastItem(stack<T> &s)
{
	T result = s.top();
	s.pop();
	if (s.empty())
	{
		return result;
	}
	
	T t1 = GetAndRemoveLastItem(s);
	s.push(result);

	return t1;
}


template<typename T>
void ReverseStack(stack<T> &s)
{
	if (s.empty())
	{
		return;
	}

	T temp = GetAndRemoveLastItem(s);
	ReverseStack(s);
	s.push(temp);
}


int main()
{
	stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);

	//PrintStack(s1);
	ReverseStack(s1);
	PrintStack(s1);

	system("pause");

	return 0;
}
