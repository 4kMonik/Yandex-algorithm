#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector <int> folders;
    int L = 0;
    int R = 0;
    int seconds = 0;
    for (int i = 0; i  < N; i++)
    {
        cin >> R;
        if (R > L)
        {
            seconds += L;
            L = R;
        }
        else
            seconds += R;
    }
    cout << seconds;
    return 0;
}
