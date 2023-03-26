#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int numberOfStickers;
    cin >> numberOfStickers;
    vector<int> stickers;
    int sticker;
    for (int i = 0; i < numberOfStickers; i++)
    {
        cin >> sticker;
        stickers.push_back(sticker);
    }
    sort(stickers.begin(), stickers.end());
    stickers.resize(distance(stickers.begin(), unique(stickers.begin(), stickers.end())));

    
    int numberOfColectioners;
    cin >> numberOfColectioners;
    
    if (numberOfStickers == 0)
        for (int i = 0; i < numberOfColectioners; i++)
        {
            cin >> sticker;
            cout << 0 << endl;
        }
    
    for (int i = 0; i < numberOfColectioners; i++)
    {
        int L = 0;
        int R = stickers.size()-1;

        
        cin >> sticker;
        
        if (sticker > stickers[R])
        {
            cout << stickers.size() << endl;
            continue;
        }
        if (sticker < stickers[L])
        {
            cout << 0 << endl;
            continue;
        }
        
        while (L < R)
        {
            if (sticker <= stickers[(L+R)/2])
                R = (L+R)/2;
            else
                L = (L+R)/2 + 1;
        }
        cout << L << endl;
    }
    
    return 0;
}