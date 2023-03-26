#include <iostream>

using namespace std;

int main()
{
    int d, x, y;
    cin >> d >> x >> y;
    if (x>= 0&& y >= 0 && y+x<=d)
        cout << 0;
    else
        if (y <= d/2 && x <= d/2) cout << 1;
        else if (x> d/2 && y-x<=0) cout << 2;
        else cout << 3;
    return 0;
}