#include <iostream>
#include <vector> ;

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> c;
    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        c.push_back(input);
    }
    
    int L = 0;
    int R;
    int max = c[L];
    c[0] = 0;
    long int count = 0;
    
    while (max > 0)
    {
        R = L + 1;
        L = -1;
        while (R < N)
        {
            if(max <= c[R])
            {
                c[R] -= max;
                if (c[R] > 0 && L == -1)
                    L = R;

            }
            else
            {
                max = c[R];
                c[R] -= max;
            }
            count += max;
            R++;
        }
        max = c[L];
        c[L] = 0;
    }

    cout << count;
    return 0;
}