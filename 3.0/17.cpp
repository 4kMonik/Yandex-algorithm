#include <iostream>
#include <queue>

using namespace std;

bool cardComp(int card1, int card2)
{
    if (card1 == 0 && card2 == 9)
        return 1;
    if (card2 == 0 && card1 == 9)
        return 0;
	if (card1 > card2)
		return 1;
    else 
        return 0;
}

int main ()
{
	queue<int> deck1, deck2;
	int input;
	for (int i = 0; i < 5; i++)
    {
    	cin >> input;
    	deck1.push(input);
    }
	for (int i = 0; i < 5; i++)
    {
    	cin >> input;
    	deck2.push(input);
    }
	int turn = 0;
	while (!deck1.empty() && !deck2.empty())
    {
        turn++;
    	if (cardComp(deck1.front(), deck2.front()))
        {
        	deck1.push(deck1.front());
        	deck1.push(deck2.front());
        }
        else
        {
        	deck2.push(deck1.front());
        	deck2.push(deck2.front());
        }
        deck1.pop();
        deck2.pop();
        if (turn == 1000000)
        {
            cout << "botva";
        	return 0;
        }
    }
	if (deck1.empty())
    	cout << "second ";
    else
    	cout << "first ";
    cout << turn;
    return 0;
}