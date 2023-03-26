#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    string input;
    cin >> input;
    
    auto stringLength = input.size();
    map<char, unsigned long> characters;
    
    for (int i = 0; i < input.size(); i++)
    {
        auto character = characters.find(input[i]);
        if (character != characters.end())
            character->second += (i+1)*(stringLength - i);
        else
            characters[input[i]] = (i+1)*(stringLength - i);
            
    }
    
    
    for (auto character: characters)
        if (character.second != 0)
            cout << character.first << ": " << character.second << endl;
    return 0;
}