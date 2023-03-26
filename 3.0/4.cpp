#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int K;
    cin >> K;
    if (N == K)
    {
        cout << -1;
        return 0;
    }
    
    int row1;
    cin >> row1;
    
    int pos1;
    cin >> pos1;
    
    int num1 = 2*row1 + pos1 - 2;
    int var = num1%K;
    if (var == 0)
        var = K;
    
    int pos2;
    if (K % 2 == 0)
        pos2 = pos1;
    else
        pos2 = pos1%2 + 1;
    
    int row2;
    int row2_1 = (num1 - K + 1)/2;
    int row2_2 = (num1 + K + 1)/2;
    
    bool rule1 = row2_1 > 0;
    bool rule2 = (2*row2_2 + pos2 - 2) <= N;
    if (rule1 && rule2)
        if (row2_2 - row1 <= row1 - row2_1)
            row2 = row2_2;
        else
            row2 = row2_1;
    else if (rule1)
        row2 = row2_1;
    else if (rule2)
        row2 = row2_2;
    else
    {
        cout << -1;
        return 0;
    }
    

    cout << row2 << " " << pos2;
    return 0;
}