#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int x;
    int  d;
    cin >> d;
    for (int i = 1; i < N; i++)
    {
        cin >> x;
        
        if ((i == N/2))
            d = x;
    }
    cout << d;
    
	return 0;
}