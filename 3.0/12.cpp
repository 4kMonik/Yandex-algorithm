#include <iostream>
#include <stack> 
#include <map>

using namespace std;

int main()
{
    map <char, char> brackets_map;
    brackets_map['('] = ')';
    brackets_map['['] = ']';
    brackets_map['{'] = '}';
    stack<char> brackets;
    char input;
    while (cin >> input)
    {
        if (input == '(' || input == '[' || input == '{')
            brackets.push(input);
        else
        {
            if (brackets.size() == 0)
            {
                cout << "no";
                return 0;
            }
            if (brackets_map[brackets.top()] != input)
            {
                cout << "no";
                return 0;
            }
            else
                brackets.pop();
        }
    }
    if (brackets.size() != 0)
        cout << "no";
    else cout << "yes";
    
    return 0;
}