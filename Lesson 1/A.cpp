#include <iostream>

using namespace std;

int main()
{
    int r, i, c;
    cin >> r >> i >> c;
    switch (i)
    {
    case 0:
        if (r!=0)
            cout << 3;
        else
            cout << c;
        break;
    case 1:
        cout << c;
        break;
    case 2: 
        cout << 2;
        break;
    case 3:
        cout << 3;
        break;
    case 4:
        if (r!=0)
            cout << 3;
        else
            cout << 4;
        break;
    case 5:
        cout << 5;
        break;
    case 6:
        cout << 0;
        break;
    case 7: 
        cout << 1;
        break;
    }
	return 0;
}