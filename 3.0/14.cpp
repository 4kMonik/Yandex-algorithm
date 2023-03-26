#include <iostream>
#include <stack>

using namespace std;



int main ()
{
	int N;
	cin >> N;

	stack <int> deadEnd;
	int input;
	int order = 1;
	deadEnd.push(0);
	for (int i = 0; i < N; i++)
    {
		cin >> input;
		if (input == order)
		{
			order++;
			while (deadEnd.top() == order)
			{
				deadEnd.pop();
				order++;
			}
		}
		else
			deadEnd.push(input);
      
    }
	if (deadEnd.size() == 1)
		cout << "YES";
	else
		cout << "NO";
  
	return 0;
}