#include <iostream>
#include <string>

using namespace std;

int main()
{
	int k;
	cin >> k;
	string S;
	cin >> S;
	int maxBeauty = 0;
	int size = S.size();
	int L, R, swaps, beauty;

	for (char letter = 'a'; letter < 'z'+1; letter++)
	{
	    swaps = k;
    	L = 0; R = 0;
    	for (L; (L < size) && (R < size) ; L++)
        {
    
        	while (swaps >=0 && R <= size)
        	{
    
        	    if (S[R] !=letter)
        	        swaps--;
        	    R++;
        	}
        	if(maxBeauty <(R - L)) maxBeauty = R-L-1;
        	if (S[L] != letter)
        	    swaps++;
        }
	}

	cout << maxBeauty;
    return 0;
}