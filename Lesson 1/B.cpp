#include <iostream>

using namespace std;

int mod(int a, int b)
{
    int q = int(a/b);
    return a - b*q;
}

int main()
{
    int N, i,j;
    cin >> N >> i >> j;
    int a =mod(N +mod(i - j-1,N),N);
    int b = mod(N + mod((j-i-1),N),N);
    if (a<b) cout << a;
    else cout << b;
	return 0;
}