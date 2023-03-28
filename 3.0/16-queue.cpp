#include <iostream>
#include <string>
#include <stack>

using namespace std;


class queue
{
public:
	stack<int> s1;
	stack<int> s2;
	int sizeOfQueue;
	queue():sizeOfQueue(0){};
	void push(int);
	int pop();
	int front();
	int size(){cout << sizeOfQueue << endl; return sizeOfQueue;};
	void clear();

};

void queue::push(int n)
{
	s1.push(n);
	sizeOfQueue++;
	cout << "ok\n";
}

int queue::pop()
{
	if (s2.empty())
    {
    	if (s1.empty())
    	{
    		cout << "error\n";
    		return -1;
    	}
    	while(!s1.empty())
    	{
    		s2.push(s1.top());
    		s1.pop();
    	}
    }
	int value = s2.top();
	s2.pop();
	sizeOfQueue--;
	cout << value << endl;
    return value;
}

int queue::front()
{
	if (s2.empty())
    {
    	if (s1.empty())
    	{
    		cout << "error\n";
    		return -1;
    	}
    	while(!s1.empty())
    	{
    		s2.push(s1.top());
    		s1.pop();
    	}
    }
	int value = s2.top();
	cout << value << endl;
    return value;
}

void queue::clear()
{
	while (!s1.empty())
    	s1.pop();
	while (!s2.empty())
    	s2.pop();
	sizeOfQueue = 0; 
	cout << "ok\n";
};

int main ()
{
    queue ints;
    string input ="";
    while (input != "exit")
    {
        cin >> input;
        if (input == "push")
        {
            int n;
            cin >> n;
            ints.push(n);
        }
        else if (input == "pop")
            ints.pop();
        else if (input == "front")
            ints.front();
        else if (input == "size")
            ints.size();
        else if (input == "clear")
            ints.clear();
    }
    cout << "bye\n";
    return 0;
}