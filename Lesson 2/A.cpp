#include <iostream>

using namespace std;

int main()
{
    int input;
    int max = 0; 
    int count = 0;
    cin >> input;
    while (input != 0)
    {
        if (input > max)
        {
            max = input;
            count = 1;
        }
        else if (input== max)
        {
            count++;
        }
		cin >> input;
    }
    cout << count;
	
	return 0;
}
