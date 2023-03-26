#include <iostream>

using namespace std;

int main()
{
    int K;
    cin >> K;
    int x_i, y_i;
    cin >> x_i >> y_i;
    int recX_left = x_i;
    int recY_down = y_i;
    int recX_right = x_i;
    int recY_up = y_i;
    for (int i = 1; i < K; i++)
    {
        cin >> x_i >> y_i;
        if (x_i > recX_right)
            recX_right = x_i;
        if (x_i < recX_left)
            recX_left = x_i;
        if (y_i > recY_up)
            recY_up = y_i;
        if (y_i < recY_down)
            recY_down = y_i;
    }
    cout << recX_left << " " << recY_down << " " << recX_right << " " << recY_up;
    return 0;
}