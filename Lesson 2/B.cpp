#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> buildings;
    int input;
    for (int i = 0; i < 10; i++)
    {
        cin >> input;
        buildings.push_back(input);
    }
    
    bool isShopMeet = false;
    vector<int> distances(buildings.size(), 0);
    for (int i = 0; i < 10; i++)
    {
        if (buildings[i] == 2)
        {
            isShopMeet = true;
            continue;
        }
        if (isShopMeet)
        {
            distances[i] = distances[i - 1] + 1;
        }
    }
    
    isShopMeet = false;
    for (int i = 9; i >= 0; i--)
    {
        if (buildings[i] == 2)
        {
            isShopMeet = true;
            continue;
        }
        if (isShopMeet)
        {
            auto d = distances[i + 1] + 1;
            if (d < distances[i] || distances[i] == 0)
                distances[i] = d;
        }
    }
    
    int max = 0;
    for (int i = 0; i < 10; i++)
    {
        if (buildings[i] == 1)
            if (distances[i] > max)
                max = distances[i];
    }
    cout << max;
    return 0;
}