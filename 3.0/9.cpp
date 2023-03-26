#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> matrix;
    int input;
    
    cin >> input;
    matrix.push_back(vector<int>());
    matrix.back().push_back(input);
    for (int j = 1; j < M; j++)
    {
        cin >> input;
        matrix.back().push_back(input);
        matrix[0][j] += matrix[0][j-1];
    }
    
    for (int i = 1; i < N; i++)
    {
        cin >> input;
        matrix.push_back(vector<int>());
        matrix.back().push_back(input);
        matrix[i][0] += matrix[i-1][0];
        for (int j = 1; j < M; j++)
        {
            cin >> input;
            matrix.back().push_back(input);
            matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
        }
    }
    
    int x1,x2,y1,y2;
    
    for (int k = 0; k < K; k++)
    {
        int sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 != 1)
            sum-= matrix[x1-2][y2-1];
        if (y1 != 1)
            sum-= matrix[x2-1][y1-2];
        if (x1 != 1 && y1!= 1)
            sum += matrix[x1 - 2][y1 - 2];
        sum += matrix[x2 - 1][y2 - 1];
        cout << sum << endl;
    }

    return 0;
}