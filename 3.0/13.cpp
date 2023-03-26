#include <iostream>
#include <stack> 

using namespace std;

int main()
{
    stack<int> nums; 
    char input;
    while (cin >> input)
        if (input > 47 && input < 58)
            nums.push(int(input) - 48);
        else
        {
            if (input == '+')
            {
                auto A = nums.top();
                nums.pop();
                nums.top() += A;
            }
            if (input == '-')
            {
                auto A = nums.top();
                nums.pop();
                nums.top() -= A;
            }
            if (input == '*')
            {
                auto A = nums.top();
                nums.pop();
                nums.top() *= A;
            }
        }
    cout << nums.top();

    return 0;
}