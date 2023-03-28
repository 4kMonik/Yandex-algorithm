#include <iostream>
#include <string>
#include <utility>

using namespace std;

class deque
{
	const int blockSize = 10;
	int **blocksArr;
	int arrSize;
	int deque_size;
	pair<int, int> _front;
	pair<int, int> _back;
	void expandblocksArr();
	void boundryCheck(pair<int,int>& );
public:
	deque();
	void push_front(int);
	void push_back(int);
	int pop_front();
	int pop_back();
	int front();
	int back();
	int size();
	void clear();
	int getArrSize() { return arrSize; };
};

deque::deque(): arrSize(10), deque_size(0)
{
	blocksArr = new int*[arrSize]{};
	for (int i = 0; i < 10; i++)
	{
		blocksArr[i] = new int[blockSize]{};
	}
	_front = make_pair(4, 5);
	_back = _front;
}

void deque::push_front(int n)
{
	if (deque_size == 0)
	{
		blocksArr[_front.first][_front.second] = n;
		deque_size++;
		cout << "ok\n";
		return;
	}
	_front.second--;
	boundryCheck(_front);

	blocksArr[_front.first][_front.second] = n;
	deque_size++;
	cout << "ok\n";
}

void deque::push_back(int n)
{
	if (deque_size == 0)
	{
		blocksArr[_back.first][_back.second] = n;
		deque_size++;
		cout << "ok\n";
		return;
	}
	if (_back.first == -2)
		_back.first = 4;
	_back.second++;
	boundryCheck(_back);

	blocksArr[_back.first][_back.second] = n;
	deque_size++;
	cout << "ok\n";
}

int deque::pop_front()
{
	if (deque_size == 0)
	{
		cout << "error\n";
		return -1;
	}
	int value = blocksArr[_front.first][_front.second];
	_front.second++;
	deque_size--;
	boundryCheck(_front);
	cout << value << endl;
	return value;
}

int deque::pop_back()
{
	if (deque_size == 0)
	{
		cout << "error\n";
		return -1;
	}
	int value = blocksArr[_back.first][_back.second];
	_back.second--;
	deque_size--;
	boundryCheck(_back);
	cout << value << endl;
	return value;
}

int deque::front()
{
	if (deque_size == 0)
	{
		cout << "error\n";
		return -1;
	}
	int value = blocksArr[_front.first][_front.second];
	cout << value << endl;
	return value;
}


int deque::back()
{
	if (deque_size == 0)
	{
		cout << "error\n";
		return -1;
	}
	int value = blocksArr[_back.first][_back.second];
	cout << value << endl;
	return value;
}

int deque::size()
{
	cout << deque_size << endl;
	return deque_size;
}

void deque::clear()
{
	deque_size = 0;
	_front = make_pair(arrSize/2 - 1, blockSize/2 -1);
	_back = _front;
	cout << "ok\n";
}

void deque::boundryCheck(pair<int, int>& border)
{
	if (border.second < 0)
	{
		border.first--;
		border.second = blockSize - 1;
	}
	if (border.first < 0)
		expandblocksArr();
	if (border.second >= blockSize)
	{
		border.first++;
		border.second = 0;
	}
	if (border.first >= arrSize)
		expandblocksArr();
}

void deque::expandblocksArr()
{
	int oldArrSize = arrSize;
	arrSize *= 2;
	int **newBlocksArr = new int*[arrSize] {};
	for (int i = 0; i < (arrSize - oldArrSize) / 2; i++)
		newBlocksArr[i] = new int[blockSize] {};
	for (int i = (arrSize - oldArrSize) / 2; i < (arrSize + oldArrSize) / 2 - 1; i++)
	{
		newBlocksArr[i] = blocksArr[i - (arrSize - oldArrSize) / 2];
	}
	for (int i = (arrSize + oldArrSize) / 2-1; i < arrSize; i++)
		newBlocksArr[i] = new int[blockSize] {};
	_front.first += (arrSize - oldArrSize) / 2;
	_back.first += (arrSize - oldArrSize) / 2;

	blocksArr = newBlocksArr;
}

int main()
{
	deque ints;
	string input;
	while (input != "exit")
	{
		cin >> input;
		if (input == "push_front")
		{
			int n;
			cin >> n;
			ints.push_front(n);
		}
		if (input == "push_back")
		{
			int n;
			cin >> n;
			ints.push_back(n);
		}
		else if (input == "pop_front")
			ints.pop_front();
		else if (input == "pop_back")
			ints.pop_back();
		else if (input == "front")
			ints.front();
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
