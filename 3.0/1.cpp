#include <iostream>
#include <map>

using namespace std;


int main()
{
    char input;
    int max = 1;
    map<char, int> hystogramm;
	do{
	    input = cin.get();
	    if (input == ' ' || input == '\n')
	        continue;
	    if(hystogramm.find(input) == hystogramm.end())
	        hystogramm[input] = 1;
	    else
	    {
	        hystogramm[input] += 1;
	        if (max < hystogramm[input]) max = hystogramm[input];
	    }
	    
	    
	    //cout << input;
	}while(!cin.eof());
	hystogramm.erase(hystogramm.begin());
	for (int i = max; i > 0; i--){
	    for (auto elem: hystogramm)
	        if (elem.second >= i)
	            cout << '#';
	        else cout << ' ';
	    cout << endl;
	}
	for (auto elem: hystogramm)
	    
	    cout << elem.first;
	return 0;
}