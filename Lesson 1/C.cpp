#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    if ((x<13) &&( y < 13) && (x!=y))
        cout << 0;
    else cout << 1;
	return 0;
}