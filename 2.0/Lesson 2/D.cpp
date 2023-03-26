#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int length;
    int numberOfBlocks;
    cin >> length >> numberOfBlocks;
    bool isOdd = length % 2;
    vector <int> blocks;
    int input;
    for (int i = 0; i < numberOfBlocks; i++)
    {
        cin >> input;
        blocks.push_back(input);
    }
    
    int L = blocks[0];
    for (int i = 0; ((blocks[i] <= length/2 && isOdd) || (blocks[i] < length/2 && !isOdd) )&& i < numberOfBlocks; i++)
    {
        L = blocks[i];
    }
    
    int R = blocks[numberOfBlocks-1];
    for (int i = numberOfBlocks-1; (blocks[i] >= length /2 && i > 0); i--)
        R = blocks[i];
    
    cout << L;
    if (L != R)
        cout << " " << R;
    return 0;
}