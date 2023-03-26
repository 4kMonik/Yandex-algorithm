#include <iostream>
#include <string>

using namespace std;

class frame
{
public:
    int value;
    frame* next;
    frame(int iniValue, frame* iniNext):value(iniValue), next(iniNext){};
    ~frame(){};
};

class stack
{
private:
    frame* head;
    int stack_size;
public:
    stack(frame* iniHead = new frame(0, NULL), int iniSize = 0): head(iniHead), stack_size(iniSize){};
    void push(int n);
    int pop();
    int back();
    int size();
    void clear();
};



void stack::push(int n)
{
    head->next = new frame(head->value, head->next);
    head->value = n;
    stack_size++;
    cout << "ok\n";
}

int stack::pop()
{
    if(head->next == NULL)
    {
        cout << "error\n";
        return 0;
    }
    int popValue = head->value;
    head->value = head->next->value;
    auto frameToDelete = head->next;
    head->next = head->next->next;
    delete frameToDelete;
    stack_size--;
    cout << popValue << endl;
    return popValue;
}

int stack::back()
{
    if(head->next == NULL)
    {
        cout << "error\n";
        return 0;
    }
    cout << head->value << endl;
    return head->value;
}

int stack::size()
{
    cout << stack_size << endl;
    return stack_size;
}

void stack::clear()
{
    head->value = 0;
    delete head->next;
    head->next = NULL;
    stack_size = 0;
    cout << "ok\n";
}

int main()
{
    stack ints;
    string input;
    while (input != "exit")
    {
        cin >> input;
        if (input == "push")
        {
            int n;
            cin >> n;
            ints.push(n);
        }
        else if (input == "pop")
            ints.pop();
        else if (input == "back")
            ints.back();
        else if (input == "size")
            ints.size();
        else if (input == "clear")
            ints.clear();
    }
    cout << "bye\n";
    return 0;
}