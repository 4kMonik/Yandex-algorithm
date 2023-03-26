#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    cin >> word;
    int price = 0;
    for (int i = 0; i < word.size()/2; i++)
    {
        if (word[i] != word[word.size() - 1 - i])
            price++;
    }
    cout << price;
    return 0;
}
